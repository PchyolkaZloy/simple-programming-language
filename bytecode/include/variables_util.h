#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iterator>

namespace bytecode {
    enum class PrimitiveTypeValue {
        Int,
        Double,
        Char,
        Bool
    };

    class Type {
    public:
        virtual ~Type() = default;

        [[nodiscard]] virtual bool isArrayType() const {
            return this->getArrayDepth() > 0;
        };

        [[nodiscard]] virtual size_t getArrayDepth() const = 0;

        virtual void setArrayDepth(size_t depth) = 0;

        [[nodiscard]] virtual std::string getTypeValue() const = 0;

        [[nodiscard]] virtual bool canCastTo(const Type &other) const = 0;

        [[nodiscard]] virtual bool isVoid() const = 0;

        [[nodiscard]] virtual bool isPrimitive() const = 0;

        [[nodiscard]] virtual bool isStructure() const {
            return !(this->isPrimitive() || this->isVoid());
        }


        [[nodiscard]] virtual Type *clone() const = 0;


        bool operator==(const Type &other) const {
            if (this == &other)
                return true;
            if (this->getTypeValue() != other.getTypeValue())
                return false;
            if (this->isArrayType())
                return other.isArrayType() && (other.getArrayDepth() == this->getArrayDepth());
            return !other.isArrayType();
        }

        bool operator!=(const Type &other) const {
            return !(this->operator==(other));
        }
    };

    class PrimitiveType : public Type {
    public:
        PrimitiveTypeValue type_value;
        size_t array_depth;

        PrimitiveType(PrimitiveTypeValue typeValue, size_t arrayDepth) : type_value(typeValue),
                                                                         array_depth(arrayDepth) {}

        [[nodiscard]] size_t getArrayDepth() const override {
            return array_depth;
        }

        void setArrayDepth(size_t depth) override {
            this->array_depth = depth;
        }

        [[nodiscard]] std::string getTypeValue() const override {
            switch (type_value) {
                case PrimitiveTypeValue::Int:
                    return "int";
                case PrimitiveTypeValue::Double:
                    return "double";
                case PrimitiveTypeValue::Char:
                    return "char";
                case PrimitiveTypeValue::Bool:
                    return "bool";
                default:
                    throw std::runtime_error("unknown primitive type");
            }
        }

        [[nodiscard]] bool canCastTo(const Type &other) const override {
            if (this->isArrayType())
                return other.getTypeValue() == "bool";
            if (other.isArrayType() || !other.isPrimitive())
                return false;
            return true;
        }

        [[nodiscard]]  bool isVoid() const override {
            return false;
        }

        [[nodiscard]] bool isPrimitive() const override {
            return true;
        }

        [[nodiscard]]  Type *clone() const override {
            return new PrimitiveType(this->type_value, this->array_depth);
        }

    };

    class StructType : public Type {
    public:
        std::string struct_name;
        size_t array_depth;

        StructType(const std::string &struct_name, size_t arrayDepth) : struct_name(struct_name),
                                                                        array_depth(arrayDepth) {}

        [[nodiscard]] size_t getArrayDepth() const override {
            return array_depth;
        }

        void setArrayDepth(size_t depth) override {
            this->array_depth = depth;
        }

        [[nodiscard]] std::string getTypeValue() const override {
            return this->struct_name;
        }

        [[nodiscard]] bool canCastTo(const Type &other) const override {
//            structs can't cast; unfortunately (luckily for me)
            return false;
        }

        [[nodiscard]]  bool isVoid() const override {
            return false;
        }

        [[nodiscard]] bool isPrimitive() const override {
            return false;
        }

        [[nodiscard]]  Type *clone() const override {
            return new StructType(this->struct_name, this->array_depth);
        }

    };

    class VoidType : public Type {
    public:
        ~VoidType() override = default;

        VoidType() = default;

        VoidType(const VoidType &other) {}

        [[nodiscard]] bool isArrayType() const override {
            return false;
        }

        [[nodiscard]] size_t getArrayDepth() const override {
            return 0;
        }

        void setArrayDepth(size_t depth) override {}

        [[nodiscard]] std::string getTypeValue() const override {
            return {};
        }

        [[nodiscard]] bool canCastTo(const Type &other) const override {
            return false;
        }

        [[nodiscard]]  bool isVoid() const override {
            return true;
        }

        [[nodiscard]] bool isPrimitive() const override {
            return false;
        }

        [[nodiscard]]  Type *clone() const override {
            return new VoidType{};
        }

    };

    struct VariableSignature {
    private:
        std::string name_;
        Type *const type_;
    public:

        VariableSignature(const std::string &name, const Type &type) : name_(name), type_(type.clone()) {}

        ~VariableSignature() {
            delete type_;
        };

        [[nodiscard]] const Type &getType() const {
            return *type_;
        }

        [[nodiscard]] const std::string &getName() const {
            return name_;
        }
    };

    template<typename T>
    concept VariableSignatureInputIterator = std::input_iterator<T> &&
                                             std::same_as<typename std::iterator_traits<T>::value_type, VariableSignature>;

    class FunctionSignature {
    private:
        std::unordered_map<std::string, Type *const> parameters_;
        std::vector<VariableSignature> parameters_vector_;
        Type *const return_type_;
        bool has_repetitions_;
    public:
        using it = std::unordered_map<std::string, Type *const>::iterator;
        using cit = std::unordered_map<std::string, Type *const>::const_iterator;

        template<VariableSignatureInputIterator InputIt>
        FunctionSignature(InputIt parameters_first, InputIt parameters_last,
                          const Type &return_type) :
                parameters_(), parameters_vector_(parameters_first, parameters_last), return_type_(return_type.clone()),
                has_repetitions_(false) {
            for (InputIt input_it = parameters_first; input_it != parameters_last; ++input_it) {
                if (parameters_.find(input_it->getName()) != parameters_.end()) {
                    this->has_repetitions_ = true;
                    break;
                }
                parameters_[input_it->getName()] = input_it->getType().clone();
            }

        }

        ~FunctionSignature() {
            for (auto it = parameters_.begin(); it != parameters_.end(); ++it) {
                delete it->second;
            }
        }

        [[nodiscard]] bool hasRepetitions() const {
            return this->has_repetitions_;
        }

        [[nodiscard]] FunctionSignature::it begin() {
            return this->parameters_.begin();
        }

        [[nodiscard]] FunctionSignature::cit cbegin() const {
            return this->parameters_.cbegin();
        }

        [[nodiscard]] FunctionSignature::it end() {
            return this->parameters_.end();
        }

        [[nodiscard]] FunctionSignature::cit cend() const {
            return this->parameters_.cend();
        }

        [[nodiscard]] FunctionSignature::it find(const std::string &parameter_name) {
            return this->parameters_.find(parameter_name);
        }

        [[nodiscard]] const Type &getReturnType() const {
            return *return_type_;
        }

        [[nodiscard]] const std::vector<VariableSignature> &getParametersVector() const {
            return parameters_vector_;
        }

    };

    class StructureSignature {
    private:
        std::unordered_map<std::string, Type *const> fields_;
        bool has_repetitions_;
    public:
        using it = std::unordered_map<std::string, Type *const>::iterator;
        using cit = std::unordered_map<std::string, Type *const>::const_iterator;

        template<VariableSignatureInputIterator InputIt>
        StructureSignature(InputIt fields_first, InputIt fields_last) :
                fields_(), has_repetitions_(false) {
            for (InputIt input_it = fields_first; input_it != fields_last; ++input_it) {
                if (fields_.find(input_it->getName()) != fields_.end()) {
                    this->has_repetitions_ = true;
                    break;
                }
                fields_[input_it->getName()] = input_it->getType().clone();
            }

        }

        ~StructureSignature() {
            for (auto it = fields_.begin(); it != fields_.end(); ++it) {
                delete it->second;
            }
        }

        [[nodiscard]] bool hasRepetitions() const {
            return this->has_repetitions_;
        }

        [[nodiscard]] StructureSignature::it begin() {
            return this->fields_.begin();
        }

        [[nodiscard]] StructureSignature::cit cbegin() const {
            return this->fields_.cbegin();
        }

        [[nodiscard]] StructureSignature::it end() {
            return this->fields_.end();
        }

        [[nodiscard]] StructureSignature::cit cend() const {
            return this->fields_.cend();
        }

        [[nodiscard]] StructureSignature::it find(const std::string &parameter_name) {
            return this->fields_.find(parameter_name);
        }


    };
}