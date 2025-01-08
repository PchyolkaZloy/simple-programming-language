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

    virtual std::shared_ptr<BaseType> operator+(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator-(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator*(const BaseType& other) const = 0;
    virtual std::shared_ptr<BaseType> operator/(const BaseType& other) const = 0;

    virtual std::shared_ptr<Bool> operator==(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator!=(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator>(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator<(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator>=(const BaseType& other) const = 0;
    virtual std::shared_ptr<Bool> operator<=(const BaseType& other) const = 0;

    TypeIndex Type = TypeIndex::Null;
    void* Value = nullptr;
};

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

    std::shared_ptr<BaseType> IntOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int) {
            IntType l = IntCast();
            IntType r = other.IntCast();
            return std::make_shared<Int>(new IntType(op(l, r)));
        }
        return {};
    }

    std::shared_ptr<BaseType> DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const;

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override {
        if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) -> IntType { return l + r; })) {
            return res;
        }
        if (auto res = DoubleOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) -> DoubleType { return l + r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    std::shared_ptr<BaseType> operator-(const BaseType& other) const override {
        if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) -> IntType { return l - r; })) {
            return res;
        }
        if (auto res = DoubleOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) -> DoubleType { return l - r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    std::shared_ptr<BaseType> operator*(const BaseType& other) const override {
        if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) -> IntType { return l * r; })) {
            return res;
        }
        if (auto res = DoubleOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) -> DoubleType { return l * r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }
    std::shared_ptr<BaseType> operator/(const BaseType& other) const override {
        if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) -> IntType { return l / r; })) {
            return res;
        }
        if (auto res = DoubleOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) -> DoubleType { return l / r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    std::shared_ptr<Bool> IntCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const IntType&, const IntType&)) const;

    std::shared_ptr<Bool> DoubleCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const;

    std::shared_ptr<Bool> operator==(const BaseType& other) const override;

    std::shared_ptr<Bool> operator!=(const BaseType& other) const override;
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

    std::shared_ptr<BaseType> OperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int ||
            other.Type == TypeIndex::Double) {
            DoubleType l = DoubleCast();
            DoubleType r = other.DoubleCast();
            return std::make_shared<Double>(new DoubleType(op(l, r)));
        }
        return nullptr;
    }

    std::shared_ptr<Bool> CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int ||
            other.Type == TypeIndex::Double) {
            DoubleType l = DoubleCast();
            DoubleType r = other.DoubleCast();
            return std::make_shared<Bool>(new BoolType(op(l, r)));
        }
        return nullptr;
    }

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override {
        if (auto res = OperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l + r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    std::shared_ptr<BaseType> operator-(const BaseType& other) const override {
        if (auto res = OperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l - r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator -\n");
    }

    std::shared_ptr<BaseType> operator*(const BaseType& other) const override {
        if (auto res = OperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l * r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator *\n");
    }

    std::shared_ptr<BaseType> operator/(const BaseType& other) const override {
        if (auto res = OperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l / r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator /\n");
    }

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

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator +\n");
    }

    std::shared_ptr<BaseType> operator-(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator -\n");
    }

    std::shared_ptr<BaseType> operator*(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator *\n");
    }

    std::shared_ptr<BaseType> operator/(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator /\n");
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

    std::shared_ptr<Bool> CompareOperatorTemplate(
        const BaseType& other,
        BoolType (*op)(const std::shared_ptr<BaseType>&, const std::shared_ptr<BaseType>&)) const {
        const Array& arr = static_cast<const Array&>(other);
        if (other.Type != TypeIndex::Array || Size() != arr.Size()) {
            return std::make_shared<Bool>(new BoolType(false));
        }
        const ValueType& l = GetArray();
        const ValueType& r = arr.GetArray();
        auto it1 = l.begin();
        auto it2 = r.begin();
        while (it1 != l.end()) {
            if (!op(*it1, *it2)) {
                return std::make_shared<Bool>(new BoolType(false));
            }
        }

        return std::make_shared<Bool>(new BoolType(true));
    }

    std::shared_ptr<BaseType> operator+(const BaseType& other) const override {
        const Array& arr = static_cast<const Array&>(other);
        if (other.Type != TypeIndex::Array) {
            throw std::invalid_argument("array can be added only with another array of the same type\n");
        }
        const ValueType& l = GetArray();
        const ValueType& r = arr.GetArray();
        std::shared_ptr<Array> res = std::make_shared<Array>();
        std::copy(l.begin(), l.end(), std::back_inserter(res->GetArray()));
        std::copy(r.begin(), r.end(), std::back_inserter(res->GetArray()));
        return res;
    }

    std::shared_ptr<BaseType> operator-(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator -\n");
    }

    std::shared_ptr<BaseType> operator*(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator *\n");
    }

    std::shared_ptr<BaseType> operator/(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator /\n");
    }

    std::shared_ptr<Bool> operator==(const BaseType& other) const override {
        auto op = [](const std::shared_ptr<BaseType>& l, const std::shared_ptr<BaseType>& r) { return (*l == *r)->BoolCast(); };
        if (auto res = CompareOperatorTemplate(other, op)) {
            return res;
        }
        return std::make_shared<Bool>(new BoolType(false));
    };

    std::shared_ptr<Bool> operator!=(const BaseType& other) const override {
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

/// int definitions

std::shared_ptr<BaseType> Int::DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return std::make_shared<Double>(new DoubleType(op(l, r)));
    }
    return nullptr;
}

std::shared_ptr<Bool> Int::IntCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const IntType&, const IntType&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int) {
        IntType l = IntCast();
        IntType r = other.IntCast();
        return std::make_shared<Bool>(new BoolType(op(l, r)));
    }
    return nullptr;
}

std::shared_ptr<Bool> Int::DoubleCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return std::make_shared<Bool>(new BoolType(op(l, r)));
    }
    return nullptr;
}

std::shared_ptr<Bool> Int::operator==(const BaseType& other) const {
    if (auto res = IntCompareOperatorTemplate(other, [](const IntType& l, const IntType& r) { return l == r; })) {
        return res;
    }
    if (auto res = DoubleCompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) < EPS; })) {
        return res;
    }
    return std::make_shared<Bool>(new BoolType(false));
}

std::shared_ptr<Bool> Int::operator!=(const BaseType& other) const {
    if (auto res = IntCompareOperatorTemplate(other, [](const IntType& l, const IntType& r) { return l != r; })) {
        return res;
    }
    if (auto res = DoubleCompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) >= EPS; })) {
        return res;
    }
    return std::make_shared<Bool>(new BoolType(true));
}
