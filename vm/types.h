#pragma once

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>
#include <memory>

#include <boost/multiprecision/cpp_int.hpp>

using cpp_int = boost::multiprecision::cpp_int;

constexpr double EPS = 1e-13;

enum class TypeIndex {
    Bool,
    Char,
    Int,
    Double,
    Array,
    Struct,
    Null,
};

struct Bool;

struct BaseType {
    using IntType = cpp_int;
    using DoubleType = double;
    using BoolType = bool;
    using CharType = char;

    BaseType(TypeIndex type, void* value)
        : Type(type)
        , Value(value) {
    }

    virtual ~BaseType() = default;

    virtual IntType IntCast() const = 0;
    virtual DoubleType DoubleCast() const = 0;
    virtual BoolType BoolCast() const = 0;

    virtual void Print(std::ostream& stream) const = 0;

    virtual std::shared_ptr<BaseType> operator+(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator-(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator*(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator/(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator%(const BaseType& other) const = 0;

#define DefBoolOperator(op)                                                   \
    virtual std::shared_ptr<Bool> operator op(const BaseType & other) const { \
        BoolType l = BoolCast();                                              \
        BoolType r = other.BoolCast();                                        \
        return std::make_shared<Bool>(new BoolType(l op r));                  \
    }

    DefBoolOperator(&&);
    DefBoolOperator(||);

    virtual std::shared_ptr<Bool> operator!() const {
        return std::make_shared<Bool>(new BoolType(!BoolCast()));
    }
    virtual std::shared_ptr<BaseType> operator-() const = 0;

    virtual std::shared_ptr<Bool> operator==(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator!=(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator>(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator<(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator>=(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator<=(const BaseType& other) const = 0;

    TypeIndex Type = TypeIndex::Null;
    void* Value = nullptr;
};

#define DefInvalidOperator(op, ret)                                                 \
    std::shared_ptr<ret> operator op(const BaseType & other) const override {       \
        throw std::invalid_argument(std::string("invalid operator ") + #op + "\n"); \
    }

struct Int: public BaseType {
    Int(IntType* value)
        : BaseType(TypeIndex::Int, value) {
    }

    virtual ~Int() = default;

    IntType IntCast() const override {
        return *reinterpret_cast<cpp_int*>(Value);
    }

    DoubleType DoubleCast() const override {
        return static_cast<DoubleType>(IntCast());
    }

    BoolType BoolCast() const override {
        return IntCast() != 0;
    }

    void Print(std::ostream& stream) const override {
        stream << IntCast();
    }

    std::shared_ptr<BaseType> IntOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const;
    std::shared_ptr<BaseType> DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const;
    std::shared_ptr<BaseType> BoolOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const;

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override;
    std::shared_ptr<BaseType> operator-(const BaseType& other) const override;
    std::shared_ptr<BaseType> operator*(const BaseType& other) const override;
    std::shared_ptr<BaseType> operator/(const BaseType& other) const override;
    std::shared_ptr<BaseType> operator%(const BaseType& other) const override;

    std::shared_ptr<BaseType> operator-() const override {
        return std::make_shared<Int>(new IntType(-IntCast()));
    }

    std::shared_ptr<Bool> IntCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const IntType&, const IntType&)) const;
    std::shared_ptr<Bool> DoubleCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const;

    std::shared_ptr<Bool> operator==(const BaseType& other) const override;
    std::shared_ptr<Bool> operator!=(const BaseType& other) const override;
    std::shared_ptr<Bool> operator>(const BaseType& other) const override;
    std::shared_ptr<Bool> operator<(const BaseType& other) const override;
    std::shared_ptr<Bool> operator>=(const BaseType& other) const override;
    std::shared_ptr<Bool> operator<=(const BaseType& other) const override;
};

struct Bool: public Int {
    Bool(BoolType* value)
        : Int(nullptr) {
        Type = TypeIndex::Bool;
        Value = value;
    }

    virtual ~Bool() = default;

    IntType IntCast() const override {
        BoolType v = *reinterpret_cast<BoolType*>(Value);
        return v;
    }

    BoolType BoolCast() const override {
        return *reinterpret_cast<BoolType*>(Value);
    }

    void Print(std::ostream& stream) const override {
        stream << BoolCast();
    }

    std::shared_ptr<Bool> operator!() {
        BoolType cur = *static_cast<BoolType*>(Value);
        return std::make_shared<Bool>(new BoolType(!cur));
    }
};

struct Char: public Int {
    Char(char* value)
        : Int(nullptr) {
        Type = TypeIndex::Char;
        Value = value;
    }

    virtual ~Char() = default;

    IntType IntCast() const override {
        char v = *reinterpret_cast<char*>(Value);
        return v;
    }

    void Print(std::ostream& stream) const override {
        stream << *reinterpret_cast<char*>(Value);
    }
};

struct Double: public BaseType {
    Double(double* value)
        : BaseType(TypeIndex::Double, value) {
    }

    virtual ~Double() = default;

    DoubleType DoubleCast() const override {
        return *reinterpret_cast<DoubleType*>(Value);
    }

    IntType IntCast() const override {
        return IntType(DoubleCast());
    }

    BoolType BoolCast() const override {
        return BoolType(DoubleCast());
    }

    void Print(std::ostream& stream) const override {
        stream << DoubleCast();
    }

    std::shared_ptr<BaseType> OperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const;

#define DefDoubleOperator(op)                                                                                      \
    std::shared_ptr<BaseType> operator op(const BaseType & other) const override {                                 \
        if (auto res = OperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l op r; })) { \
            return res;                                                                                            \
        }                                                                                                          \
        throw std::invalid_argument(std::string("invalid usage of operator") + #op + "\n");                        \
    }

    DefDoubleOperator(+);
    DefDoubleOperator(-);
    DefDoubleOperator(*);
    DefDoubleOperator(/);

    DefInvalidOperator(%, BaseType);

    std::shared_ptr<BaseType> operator-() const override {
        return std::make_shared<Double>(new DoubleType(-DoubleCast()));
    }

    std::shared_ptr<Bool> CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const;

    std::shared_ptr<Bool> operator==(const BaseType& other) const override {
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) < EPS; })) {
            return res;
        }
        return std::make_shared<Bool>(new BoolType(false));
    }

    std::shared_ptr<Bool> operator!=(const BaseType& other) const override {
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) >= EPS; })) {
            return res;
        }
        return std::make_shared<Bool>(new BoolType(true));
    }

#define DefDoubleCompareOperator(op)                                                                                      \
    std::shared_ptr<Bool> operator op(const BaseType & other) const override {                                            \
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l op r; })) { \
            return res;                                                                                                   \
        }                                                                                                                 \
        throw std::invalid_argument(std::string("invalid usage of operator") + #op + "\n");                               \
    }

    DefDoubleCompareOperator(>);
    DefDoubleCompareOperator(<);
    DefDoubleCompareOperator(>=);
    DefDoubleCompareOperator(<=);
};

struct Struct: public BaseType {
    using ValueType = std::map<std::string, std::shared_ptr<BaseType>>;

    Struct()
        : BaseType(TypeIndex::Struct, new ValueType()) {
    }

    const ValueType& GetMap() const {
        return *reinterpret_cast<ValueType*>(Value);
    }

    ValueType& GetMap() {
        return *reinterpret_cast<ValueType*>(Value);
    }

    virtual ~Struct() = default;

    DoubleType DoubleCast() const override {
        throw std::invalid_argument("struct is not convertible to double\n");
    }

    IntType IntCast() const override {
        throw std::invalid_argument("struct is not convertible to int\n");
    }

    BoolType BoolCast() const override {
        throw std::invalid_argument("struct is not convertible to bool\n");
    }

    void Print(std::ostream& stream) const override {
        stream << "{";
        std::string_view sep = "";
        for (const auto& [k, v] : GetMap()) {
            stream << sep;
            stream << k << ": ";
            v->Print(stream);
            sep = ", ";
        }
        stream << "}";
    }

    DefInvalidOperator(+, BaseType);
    DefInvalidOperator(-, BaseType);
    DefInvalidOperator(*, BaseType);
    DefInvalidOperator(/, BaseType);
    DefInvalidOperator(%, BaseType);
    DefInvalidOperator(&&, Bool);
    DefInvalidOperator(||, Bool);
    DefInvalidOperator(>, Bool);
    DefInvalidOperator(<, Bool);
    DefInvalidOperator(>=, Bool);
    DefInvalidOperator(<=, Bool);

    std::shared_ptr<BaseType> operator-() const override {
        throw std::invalid_argument("unary minus can be applied only to numeric types");
    }

    std::shared_ptr<Bool> operator==(const BaseType& other) const override {
        if (other.Type != TypeIndex::Struct) {
            return std::make_shared<Bool>(new BoolType(false));
        }
        const Struct& arr = static_cast<const Struct&>(other);
        const ValueType& l = GetMap();
        const ValueType& r = arr.GetMap();
        if (l != r) {
            return std::make_shared<Bool>(new BoolType(false));
        }
        // bool typesEqual = std::all_of(
        //     l.begin(),
        //     l.end(),
        //     [&r](const std::pair<std::string, BaseType*>& pair1, const std::pair<std::string, BaseType*>& pair2) {
        //         pair1.second->Type == r.at(pair1.first)->Type;
        //     });
        return std::make_shared<Bool>(new BoolType(true));
    }

    std::shared_ptr<Bool> operator!=(const BaseType& other) const override {
        Bool& equal = *(*this == other);
        return !equal;
    }
};

struct Array: public BaseType {
    using ValueType = std::vector<std::shared_ptr<BaseType>>;
    Array()
        : BaseType(TypeIndex::Array, new ValueType()) {
    }

    Array(ValueType&& value)
        : BaseType(TypeIndex::Array, new ValueType(std::move(value))) {
    }

    Array(const ValueType& value)
        : BaseType(TypeIndex::Array, new ValueType(value)) {
    }

    virtual ~Array() = default;

    DoubleType DoubleCast() const override {
        throw std::invalid_argument("array cannot be interpreted as double\n");
    }

    IntType IntCast() const override {
        throw std::invalid_argument("array cannot be interpreted as int\n");
    }

    BoolType BoolCast() const override {
        return reinterpret_cast<ValueType*>(Value)->size() > 0;
    }

    const ValueType& GetArray() const {
        return *reinterpret_cast<ValueType*>(Value);
    }

    ValueType& GetArray() {
        return *reinterpret_cast<ValueType*>(Value);
    }

    void Print(std::ostream& stream) const override {
        stream << "{";
        std::string_view sep = "";
        for (const auto& i : GetArray()) {
            stream << sep;
            i->Print(stream);
            sep = ", ";
        }
        stream << "}";
    }

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override;

    DefInvalidOperator(-, BaseType);
    DefInvalidOperator(*, BaseType);
    DefInvalidOperator(/, BaseType);
    DefInvalidOperator(%, BaseType);
    DefInvalidOperator(>, Bool);
    DefInvalidOperator(<, Bool);
    DefInvalidOperator(>=, Bool);
    DefInvalidOperator(<=, Bool);

    std::shared_ptr<BaseType> operator-() const override {
        throw std::invalid_argument("unary minus can be applied only to numeric types");
    }

    std::shared_ptr<Bool> CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const std::shared_ptr<BaseType>&, const std::shared_ptr<BaseType>&)) const;

    std::shared_ptr<Bool> operator==(const BaseType& other) const override {
        auto op = [](const std::shared_ptr<BaseType>& l, const std::shared_ptr<BaseType>& r) { return (*l == *r)->BoolCast(); };
        if (auto res = CompareOperatorTemplate(other, op)) {
            return res;
        }
        return std::make_shared<Bool>(new BoolType(false));
    };

    std::shared_ptr<Bool> operator!=(const BaseType& other) const override {
        // TODO BUG HERE
        auto op = [](const std::shared_ptr<BaseType>& l, const std::shared_ptr<BaseType>& r) { return (*l != *r)->BoolCast(); };
        if (auto res = CompareOperatorTemplate(other, op)) {
            return res;
        }
        return std::make_shared<Bool>(new BoolType(true));
    }

    const std::shared_ptr<BaseType>& operator[](const IntType& idx) const {
        return GetArray()[static_cast<size_t>(idx)];
    }

    std::shared_ptr<BaseType>& operator[](const IntType& idx) {
        return GetArray()[static_cast<size_t>(idx)];
    }

    const std::shared_ptr<BaseType>& operator[](const Int& idx) const {
        return GetArray()[static_cast<size_t>(idx.IntCast())];
    }

    std::shared_ptr<BaseType>& operator[](const Int& idx) {
        return GetArray()[static_cast<size_t>(idx.IntCast())];
    }

    void Append(std::shared_ptr<BaseType>&& element) {
        GetArray().push_back(std::move(element));
    }

    void Append(const std::shared_ptr<BaseType>& element) {
        GetArray().push_back(element);
    }

    size_t Size() const {
        return GetArray().size();
    }
};
