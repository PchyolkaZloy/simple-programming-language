#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

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

        [[nodiscard]] virtual std::string getTypeValue() const = 0;

        [[nodiscard]] virtual bool canCastTo(const Type &other) const = 0;

        [[nodiscard]] virtual Type *copyToNew() const = 0;


        bool operator==(const Type &other) const {
            if (this->getTypeValue() != other.getTypeValue())
                return false;
            if (this->isArrayType())
                return other.isArrayType() && (other.getArrayDepth() == this->getArrayDepth());
            return !other.isArrayType();
        }

        bool operator!=(const Type &other) const {
            return !(*this == other);
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
            if (other.isArrayType() || this->isArrayType())
                return false;
            if (other.getTypeValue() == "double" || other.getTypeValue() == "int" || other.getTypeValue() == "bool")
                return true;
            if (other.getTypeValue() == "char")
                return this->type_value != PrimitiveTypeValue::Int;
            return false;
        }

        [[nodiscard]] Type *copyToNew() const override {
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

        [[nodiscard]] std::string getTypeValue() const override {
            return this->struct_name;
        }

        [[nodiscard]] bool canCastTo(const Type &other) const override {
//            structs can't cast; unfortunately (luckily for me)
            return false;
        }

        [[nodiscard]] Type *copyToNew() const override {
            return new StructType(this->struct_name, this->array_depth);
        }

    };

    struct VariableSignature {
    private:
        std::string name_;
        Type *type_ptr_;
    public:

        VariableSignature(const std::string &name, const Type &type) : name_(name), type_ptr_(type.copyToNew()) {}

        ~VariableSignature() {
            delete type_ptr_;
        }

        [[nodiscard]] const Type &getType() const {
            return *type_ptr_;
        }

        [[nodiscard]] const std::string &getName() const {
            return name_;
        }
    };

    class FunctionSignature {
    private:
        std::vector<VariableSignature> parameters_;
        Type *return_type_ptr_;
    public:
        template<class InputIt>
        FunctionSignature(InputIt parameters_first, InputIt parameters_last, const Type &return_type) :
                parameters_(parameters_first, parameters_last), return_type_ptr_(return_type.copyToNew()) {}

        [[nodiscard]] const std::vector<VariableSignature> &getParameters() const {
            return parameters_;
        }

        [[nodiscard]] const Type &getReturnType() const {
            return *return_type_ptr_;
        }

    };
}