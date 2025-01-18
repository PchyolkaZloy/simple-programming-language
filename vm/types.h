#pragma once

#include "type_index.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>
#include <variant>
#include <memory>

#include <boost/multiprecision/cpp_int.hpp>

#include "gc.h"

using cpp_int = boost::multiprecision::cpp_int;

constexpr double EPS = 1e-13;

struct Bool;

struct BaseType : public gc::BaseObject {
    using IntType = cpp_int;
    using DoubleType = double;
    using BoolType = bool;
    using CharType = char;
    using ArrayType = std::vector<gc::Ref<BaseType>>;
    using StructType = std::map<std::string, gc::Ref<BaseType>>;

    // optimize heap allocations
    static gc::Ref<Bool> FALSE;
    static gc::Ref<Bool> TRUE;

    template <typename T>
    BaseType(TypeIndex type, const T& value)
        : Type(type)
        , Value(value) {
    }

    template <typename T>
    BaseType(TypeIndex type, T&& value)
        : Type(type)
        , Value(std::move(value)) {
    }

    virtual ~BaseType() = default;

    virtual IntType IntCast() const = 0;
    virtual DoubleType DoubleCast() const = 0;
    virtual BoolType BoolCast() const = 0;

    virtual void Print(std::ostream& stream) const = 0;

    virtual gc::Ref<BaseType> operator+(const BaseType& other) const = 0;
    virtual gc::Ref<BaseType> operator-(const BaseType& other) const = 0;
    virtual gc::Ref<BaseType> operator*(const BaseType& other) const = 0;
    virtual gc::Ref<BaseType> operator/(const BaseType& other) const = 0;
    virtual gc::Ref<BaseType> operator%(const BaseType& other) const = 0;

#define DefBoolOperator(op)                                                   \
    virtual gc::Ref<Bool> operator op(const BaseType & other) const {         \
        BoolType l = BoolCast();                                              \
        BoolType r = other.BoolCast();                                        \
        return l op r ? TRUE : FALSE;                                         \
    }

    DefBoolOperator(&&);
    DefBoolOperator(||);

    virtual gc::Ref<Bool> operator!() const {
        return !BoolCast() ? TRUE : FALSE;
    }
    virtual gc::Ref<BaseType> operator-() const = 0;

    virtual gc::Ref<Bool> operator==(const BaseType& other) const = 0;
    virtual gc::Ref<Bool> operator!=(const BaseType& other) const = 0;
    virtual gc::Ref<Bool> operator>(const BaseType& other) const = 0;
    virtual gc::Ref<Bool> operator<(const BaseType& other) const = 0;
    virtual gc::Ref<Bool> operator>=(const BaseType& other) const = 0;
    virtual gc::Ref<Bool> operator<=(const BaseType& other) const = 0;

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        return {};
    }

    TypeIndex Type = TypeIndex::Null;
    std::variant<IntType, BoolType, CharType, DoubleType, StructType, ArrayType> Value;
};

#define DefInvalidOperator(op, ret)                                                 \
    gc::Ref<ret> operator op(const BaseType & other) const override {               \
        throw std::invalid_argument(std::string("invalid operator ") + #op + "\n"); \
    }

struct Int: public BaseType {
    Int()
        : BaseType(TypeIndex::Int, 0) {
    }

    Int(const IntType& value)
        : BaseType(TypeIndex::Int, value) {
    }

    Int(IntType&& value)
        : BaseType(TypeIndex::Int, std::move(value)) {
    }

    virtual ~Int() = default;

    IntType IntCast() const override {
        return std::get<IntType>(Value);
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

    gc::Ref<BaseType> IntOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const;
    gc::Ref<BaseType> DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const;
    gc::Ref<BaseType> BoolOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const;

    gc::Ref<BaseType> operator+(const BaseType& other) const override;
    gc::Ref<BaseType> operator-(const BaseType& other) const override;
    gc::Ref<BaseType> operator*(const BaseType& other) const override;
    gc::Ref<BaseType> operator/(const BaseType& other) const override;
    gc::Ref<BaseType> operator%(const BaseType& other) const override;

    gc::Ref<BaseType> operator-() const override {
        return gc::gc.create<Int>(new Int(-IntCast()));
    }

    gc::Ref<Bool> IntCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const IntType&, const IntType&)) const;
    gc::Ref<Bool> DoubleCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const;

    gc::Ref<Bool> operator==(const BaseType& other) const override;
    gc::Ref<Bool> operator!=(const BaseType& other) const override;
    gc::Ref<Bool> operator>(const BaseType& other) const override;
    gc::Ref<Bool> operator<(const BaseType& other) const override;
    gc::Ref<Bool> operator>=(const BaseType& other) const override;
    gc::Ref<Bool> operator<=(const BaseType& other) const override;

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        return {};
    }
};

struct Bool: public Int {
    Bool(const BoolType& value) {
        Type = TypeIndex::Bool;
        Value = value;
    }

    virtual ~Bool() = default;

    IntType IntCast() const override {
        return BoolCast();
    }

    BoolType BoolCast() const override {
        return std::get<BoolType>(Value);
    }

    void Print(std::ostream& stream) const override {
        stream << BoolCast();
    }

    gc::Ref<Bool> operator!() {
        return !BoolCast() ? TRUE : FALSE;
    }

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        return {};
    }
};

struct Char: public Int {
    Char(const CharType& value) {
        Type = TypeIndex::Char;
        Value = value;
    }

    virtual ~Char() = default;

    IntType IntCast() const override {
        return std::get<CharType>(Value);
    }

    void Print(std::ostream& stream) const override {
        stream << std::get<CharType>(Value);
    }

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        return {};
    }
};

struct Double: public BaseType {
    Double(const DoubleType& value)
        : BaseType(TypeIndex::Double, value) {
    }

    virtual ~Double() = default;

    DoubleType DoubleCast() const override {
        return std::get<DoubleType>(Value);
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

    gc::Ref<BaseType> OperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const;

#define DefDoubleOperator(op)                                                                                      \
    gc::Ref<BaseType> operator op(const BaseType & other) const override {                                         \
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

    gc::Ref<BaseType> operator-() const override {
        Double temp = Double(-DoubleCast());
        return gc::gc.create(&temp);
    }

    gc::Ref<Bool> CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const;

    gc::Ref<Bool> operator==(const BaseType& other) const override {
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) < EPS; })) {
            return res;
        }
        return FALSE;
    }

    gc::Ref<Bool> operator!=(const BaseType& other) const override {
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) >= EPS; })) {
            return res;
        }
        return TRUE;
    }

#define DefDoubleCompareOperator(op)                                                                                      \
    gc::Ref<Bool> operator op(const BaseType & other) const override {                                                    \
        if (auto res = CompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l op r; })) { \
            return res;                                                                                                   \
        }                                                                                                                 \
        throw std::invalid_argument(std::string("invalid usage of operator") + #op + "\n");                               \
    }

    DefDoubleCompareOperator(>);
    DefDoubleCompareOperator(<);
    DefDoubleCompareOperator(>=);
    DefDoubleCompareOperator(<=);

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        return {};
    }
};

struct Struct: public BaseType {
    using ValueType = std::map<std::string, gc::Ref<BaseType>>;

    Struct()
        : BaseType(TypeIndex::Struct, ValueType()) {
    }

    const ValueType& GetMap() const {
        return std::get<StructType>(Value);
    }

    ValueType& GetMap() {
        return std::get<StructType>(Value);
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
            v.object().Print(stream);
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

    gc::Ref<BaseType> operator-() const override {
        throw std::invalid_argument("unary minus can be applied only to numeric types");
    }

    gc::Ref<Bool> operator==(const BaseType& other) const override {
        if (other.Type != TypeIndex::Struct) {
            return FALSE;
        }
        const Struct& arr = static_cast<const Struct&>(other);
        const ValueType& l = GetMap();
        const ValueType& r = arr.GetMap();
        if (l != r) {
            return FALSE;
        }
        // bool typesEqual = std::all_of(
        //     l.begin(),
        //     l.end(),
        //     [&r](const std::pair<std::string, BaseType*>& pair1, const std::pair<std::string, BaseType*>& pair2) {
        //         pair1.second->Type == r.at(pair1.first)->Type;
        //     });
        return TRUE;
    }

    gc::Ref<Bool> operator!=(const BaseType& other) const override {
        Bool& equal = *(*this == other);
        return !equal;
    }

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        // TODO: Implement
        return {};
    }
};

struct Array: public BaseType {
    using ValueType = std::vector<gc::Ref<BaseType>>;
    Array()
        : BaseType(TypeIndex::Array, ValueType()) {
    }

    Array(ValueType&& value)
        : BaseType(TypeIndex::Array, std::move(value)) {
    }

    Array(const ValueType& value)
        : BaseType(TypeIndex::Array, value) {
    }

    virtual ~Array() = default;

    DoubleType DoubleCast() const override {
        throw std::invalid_argument("array cannot be interpreted as double\n");
    }

    IntType IntCast() const override {
        throw std::invalid_argument("array cannot be interpreted as int\n");
    }

    BoolType BoolCast() const override {
        return GetArray().size() > 0;
    }

    const ValueType& GetArray() const {
        return std::get<ArrayType>(Value);
    }

    ValueType& GetArray() {
        return std::get<ArrayType>(Value);
    }

    void Print(std::ostream& stream) const override {
        stream << "{";
        std::string_view sep = "";
        for (const auto& i : GetArray()) {
            stream << sep;
            i.object().Print(stream);
            sep = ", ";
        }
        stream << "}";
    }

    gc::Ref<BaseType> operator+(const BaseType& other) const override;

    DefInvalidOperator(-, BaseType);
    DefInvalidOperator(*, BaseType);
    DefInvalidOperator(/, BaseType);
    DefInvalidOperator(%, BaseType);
    DefInvalidOperator(>, Bool);
    DefInvalidOperator(<, Bool);
    DefInvalidOperator(>=, Bool);
    DefInvalidOperator(<=, Bool);

    gc::Ref<BaseType> operator-() const override {
        throw std::invalid_argument("unary minus can be applied only to numeric types");
    }

    gc::Ref<Bool> CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const gc::Ref<BaseType>&, const gc::Ref<BaseType>&)) const;

    gc::Ref<Bool> operator==(const BaseType& other) const override {
        auto op = [](const gc::Ref<BaseType>& l, const gc::Ref<BaseType>& r) { return (l.object() == r.object()).object().BoolCast(); };
        if (auto res = CompareOperatorTemplate(other, op)) {
            return res;
        }
        return FALSE;
    };

    gc::Ref<Bool> operator!=(const BaseType& other) const override {
        // TODO BUG HERE
        auto op = [](const gc::Ref<BaseType>& l, const gc::Ref<BaseType>& r) { return (l.object() != r.object()).object().BoolCast(); };
        if (auto res = CompareOperatorTemplate(other, op)) {
            return res;
        }
        return TRUE;
    }

    const gc::Ref<BaseType>& operator[](const IntType& idx) const {
        return GetArray()[static_cast<size_t>(idx)];
    }

    gc::Ref<BaseType>& operator[](const IntType& idx) {
        return GetArray()[static_cast<size_t>(idx)];
    }

    const gc::Ref<BaseType>& operator[](const Int& idx) const {
        return GetArray()[static_cast<size_t>(idx.IntCast())];
    }

    gc::Ref<BaseType>& operator[](const Int& idx) {
        return GetArray()[static_cast<size_t>(idx.IntCast())];
    }

    void Append(gc::Ref<BaseType>&& element) {
        GetArray().push_back(std::move(element));
    }

    void Append(const gc::Ref<BaseType>& element) {
        GetArray().push_back(element);
    }

    gc::Ref<BaseType> Pop() {
        auto& arr = GetArray();
        auto ret = std::move(arr.back());
        arr.pop_back();
        return ret;
    }

    size_t Size() const {
        return GetArray().size();
    }

    // GC
    std::vector<gc::Ref<gc::BaseObject>> getChildren() override {
        // TODO: implement
        return {};
    }
};
