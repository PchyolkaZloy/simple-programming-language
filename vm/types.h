#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>

#include <boost/multiprecision/cpp_int.hpp>

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
    BaseType(TypeIndex type, void* value)
        : Type(type)
        , Value(value) {
    }

    virtual ~BaseType() = default;

    virtual int IntCast() const = 0;
    virtual double DoubleCast() const = 0;
    virtual bool BoolCast() const = 0;

    virtual BaseType* operator+(const BaseType& other) const = 0;
    virtual BaseType* operator-(const BaseType& other) const = 0;
    virtual BaseType* operator*(const BaseType& other) const = 0;
    virtual BaseType* operator/(const BaseType& other) const = 0;

    virtual Bool* operator==(const BaseType& other) const = 0;
    virtual Bool* operator!=(const BaseType& other) const = 0;

    TypeIndex Type = TypeIndex::Null;
    void* Value = nullptr;
};

struct Int: public BaseType {
    Int(int* value)
        : BaseType(TypeIndex::Int, value) {
    }

    virtual ~Int() = default;

    int IntCast() const override {
        return *reinterpret_cast<int*>(Value);
    }

    double DoubleCast() const override {
        return static_cast<double>(IntCast());
    }

    bool BoolCast() const override {
        return IntCast() != 0;
    }

    BaseType* IntOperatorTemplate(const BaseType& other, int (*op)(int, int)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int) {
            int l = IntCast();
            int r = other.IntCast();
            return new Int(new int(op(l, r)));
        }
        return nullptr;
    }

    BaseType* DoubleOperatorTemplate(const BaseType& other, double (*op)(double, double)) const;

    BaseType* operator+(const BaseType& other) const override {
        if (BaseType *res = IntOperatorTemplate(other, [](int l, int r) { return l + r; })) {
            return res;
        }
        if (BaseType *res = DoubleOperatorTemplate(other, [](double l, double r) { return l + r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    BaseType* operator-(const BaseType& other) const override {
        if (BaseType *res = IntOperatorTemplate(other, [](int l, int r) { return l - r; })) {
            return res;
        }
        if (BaseType *res = DoubleOperatorTemplate(other, [](double l, double r) { return l - r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    BaseType* operator*(const BaseType& other) const override {
        if (BaseType *res = IntOperatorTemplate(other, [](int l, int r) { return l * r; })) {
            return res;
        }
        if (BaseType *res = DoubleOperatorTemplate(other, [](double l, double r) { return l * r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }
    BaseType* operator/(const BaseType& other) const override {
        if (BaseType *res = IntOperatorTemplate(other, [](int l, int r) { return l / r; })) {
            return res;
        }
        if (BaseType *res = DoubleOperatorTemplate(other, [](double l, double r) { return l / r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    Bool* IntCompareOperatorTemplate(const BaseType& other, bool (*op)(int, int)) const;

    Bool* DoubleCompareOperatorTemplate(const BaseType& other, bool (*op)(double, double)) const;

    Bool* operator==(const BaseType& other) const override;

    Bool* operator!=(const BaseType& other) const override;
};

struct Bool: public Int {
    Bool(bool* value)
        : Int(nullptr) {
        Type = TypeIndex::Bool;
        Value = value;
    }

    virtual ~Bool() = default;

    int IntCast() const override {
        bool v = *reinterpret_cast<bool*>(Value);
        return static_cast<int>(v);
    }

    Bool* operator!() {
        bool cur = *static_cast<bool*>(Value);
        return new Bool(new bool(!cur));
    }
};

struct Char: public Int {
    Char(char* value)
        : Int(nullptr) {
        Type = TypeIndex::Char;
        Value = value;
    }

    virtual ~Char() = default;

    int IntCast() const override {
        bool v = *reinterpret_cast<char*>(Value);
        return static_cast<int>(v);
    }
};

struct Double: public BaseType {
    Double(double* value)
        : BaseType(TypeIndex::Double, value) {
    }

    virtual ~Double() = default;

    double DoubleCast() const override {
        return *reinterpret_cast<double*>(Value);
    }

    int IntCast() const override {
        return static_cast<int>(DoubleCast());
    }

    bool BoolCast() const override {
        return static_cast<bool>(DoubleCast());
    }

    BaseType* OperatorTemplate(const BaseType& other, double (*op)(double, double)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int ||
            other.Type == TypeIndex::Double) {
            double l = DoubleCast();
            double r = other.DoubleCast();
            return new Double(new double(op(l, r)));
        }
        return nullptr;
    }

    Bool* CompareOperatorTemplate(const BaseType& other, bool (*op)(double, double)) const {
        if (other.Type == TypeIndex::Bool ||
            other.Type == TypeIndex::Char ||
            other.Type == TypeIndex::Int ||
            other.Type == TypeIndex::Double) {
            double l = DoubleCast();
            double r = other.DoubleCast();
            return new Bool(new bool(op(l, r)));
        }
        return nullptr;
    }

    BaseType* operator+(const BaseType& other) const override {
        if (BaseType *res = OperatorTemplate(other, [](double l, double r) { return l + r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator +\n");
    }

    BaseType* operator-(const BaseType& other) const override {
        if (BaseType *res = OperatorTemplate(other, [](double l, double r) { return l - r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator -\n");
    }

    BaseType* operator*(const BaseType& other) const override {
        if (BaseType *res = OperatorTemplate(other, [](double l, double r) { return l * r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator *\n");
    }

    BaseType* operator/(const BaseType& other) const override {
        if (BaseType *res = OperatorTemplate(other, [](double l, double r) { return l / r; })) {
            return res;
        }
        throw std::invalid_argument("invalid usage of operator /\n");
    }

    Bool* operator==(const BaseType& other) const override {
        if (Bool *res = CompareOperatorTemplate(other, [](double l, double r) { return abs(l - r) < EPS; })) {
            return res;
        }
        return new Bool(new bool(false));
    }

    Bool* operator!=(const BaseType& other) const override {
        if (Bool *res = CompareOperatorTemplate(other, [](double l, double r) { return abs(l - r) >= EPS; })) {
            return res;
        }
        return new Bool(new bool(true));
    }
};

struct Null: public BaseType {
    Null()
        : BaseType(TypeIndex::Null, nullptr) {
    }

    virtual ~Null() = default;

    double DoubleCast() const override {
        return 0.0;
    }

    int IntCast() const override {
        return 0;
    }

    bool BoolCast() const override {
        return false;
    }

    BaseType* operator+(const BaseType& other) const override {
        throw std::invalid_argument("null has no operator +\n");
    }

    BaseType* operator-(const BaseType& other) const override {
        throw std::invalid_argument("null has no operator -\n");
    }

    BaseType* operator*(const BaseType& other) const override {
        throw std::invalid_argument("null has no operator *\n");
    }

    BaseType* operator/(const BaseType& other) const override {
        throw std::invalid_argument("null has no operator /\n");
    }

    Bool* operator==(const BaseType& other) const override {
        return new Bool(new bool(other.Type == TypeIndex::Null));
    }

    Bool* operator!=(const BaseType& other) const override {
        return new Bool(new bool(other.Type != TypeIndex::Null));
    }
};

struct Struct: public BaseType {
    using ValueType = std::map<std::string, BaseType*>;

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

    double DoubleCast() const override {
        throw std::invalid_argument("struct is not convertible to double\n");
    }

    int IntCast() const override {
        throw std::invalid_argument("struct is not convertible to int\n");
    }

    bool BoolCast() const override {
        throw std::invalid_argument("struct is not convertible to bool\n");
    }

    BaseType* operator+(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator +\n");
    }

    BaseType* operator-(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator -\n");
    }

    BaseType* operator*(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator *\n");
    }

    BaseType* operator/(const BaseType& other) const override {
        throw std::invalid_argument("struct has no operator /\n");
    }

    Bool* operator==(const BaseType& other) const override {
        if (other.Type != TypeIndex::Struct) {
            return new Bool(new bool(false));
        }
        const Struct& arr = static_cast<const Struct&>(other);
        const ValueType& l = GetMap();
        const ValueType& r = arr.GetMap();
        if (l != r) {
            return new Bool(new bool(false));
        }
        // bool typesEqual = std::all_of(
        //     l.begin(),
        //     l.end(),
        //     [&r](const std::pair<std::string, BaseType*>& pair1, const std::pair<std::string, BaseType*>& pair2) {
        //         pair1.second->Type == r.at(pair1.first)->Type;
        //     });
        return new Bool(new bool(false));
    }

    Bool* operator!=(const BaseType& other) const override {
        Bool& equal = *(*this == other);
        return !equal;
    }
};

struct Array: public BaseType {
    using ValueType = std::vector<BaseType*>;
    Array(TypeIndex elementType)
        : BaseType(TypeIndex::Array, new std::vector<BaseType*>())
        , ElementType(elementType) {
    }

    virtual ~Array() = default;

    double DoubleCast() const override {
        throw std::invalid_argument("array cannot be interpreted as double\n");
    }

    int IntCast() const override {
        throw std::invalid_argument("array cannot be interpreted as int\n");
    }

    bool BoolCast() const override {
        return reinterpret_cast<ValueType*>(Value)->size() > 0;
    }

    const ValueType& GetArray() const {
        return *reinterpret_cast<ValueType*>(Value);
    }

    ValueType& GetArray() {
        return *reinterpret_cast<ValueType*>(Value);
    }

    Bool* CompareOperatorTemplate(const BaseType& other, bool (*op)(const BaseType*, const BaseType*)) const {
        const Array& arr = static_cast<const Array&>(other);
        if (other.Type != TypeIndex::Array || Size() != arr.Size()) {
            return new Bool(new bool(false));
        }
        const ValueType& l = GetArray();
        const ValueType& r = arr.GetArray();
        auto it1 = l.begin();
        auto it2 = r.begin();
        while (it1 != l.end()) {
            if (!op(*it1, *it2)) {
                return new Bool(new bool(false));
            }
        }

        return new Bool(new bool(true));
    }

    BaseType* operator+(const BaseType& other) const override {
        const Array& arr = static_cast<const Array&>(other);
        if (other.Type != TypeIndex::Array || arr.ElementType != ElementType) {
            throw std::invalid_argument("array can be added only with another array of the same type\n");
        }
        const ValueType& l = GetArray();
        const ValueType& r = arr.GetArray();
        Array* res = new Array(ElementType);
        std::copy(l.begin(), l.end(), std::back_inserter(res->GetArray()));
        std::copy(r.begin(), r.end(), std::back_inserter(res->GetArray()));
        return res;
    }

    BaseType* operator-(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator -\n");
    }

    BaseType* operator*(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator *\n");
    }

    BaseType* operator/(const BaseType& other) const override {
        throw std::invalid_argument("array has not operator /\n");
    }

    Bool* operator==(const BaseType& other) const override {
        if (Bool *res = CompareOperatorTemplate(other, [](const BaseType* l, const BaseType* r) { return (*l == *r)->BoolCast(); })) {
            return res;
        }
        return new Bool(new bool(false));
    };

    Bool* operator!=(const BaseType& other) const override {
        if (Bool *res = CompareOperatorTemplate(other, [](const BaseType* l, const BaseType* r) { return (*l != *r)->BoolCast(); })) {
            return res;
        }
        return new Bool(new bool(true));
    }

    const BaseType& operator[](size_t idx) const {
        return *GetArray()[idx];
    }

    BaseType& operator[](size_t idx) {
        return *GetArray()[idx];
    }

    void Append(BaseType* element) {
        GetArray().push_back(element);
    }

    size_t Size() const {
        return GetArray().size();
    }

    TypeIndex ElementType;
};

/// int definitions

BaseType* Int::DoubleOperatorTemplate(const BaseType& other, double (*op)(double, double)) const {
    if (other.Type == TypeIndex::Double) {
        double l = DoubleCast();
        double r = other.DoubleCast();
        return new Double(new double(op(l, r)));
    }
    return nullptr;
}

Bool* Int::IntCompareOperatorTemplate(const BaseType& other, bool (*op)(int, int)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int) {
        int l = IntCast();
        int r = other.IntCast();
        return new Bool(new bool(op(l, r)));
    }
    return nullptr;
}

Bool* Int::DoubleCompareOperatorTemplate(const BaseType& other, bool (*op)(double, double)) const {
    if (other.Type == TypeIndex::Double) {
        double l = DoubleCast();
        double r = other.DoubleCast();
        return new Bool(new bool(op(l, r)));
    }
    return nullptr;
}

Bool* Int::operator==(const BaseType& other) const {
    if (Bool *res = IntCompareOperatorTemplate(other, [](int l, int r) { return l == r; })) {
        return res;
    }
    if (Bool *res = DoubleCompareOperatorTemplate(other, [](double l, double r) { return abs(l - r) < EPS; })) {
        return res;
    }
    return new Bool(new bool(false));
}

Bool* Int::operator!=(const BaseType& other) const {
    if (Bool *res = IntCompareOperatorTemplate(other, [](int l, int r) { return l != r; })) {
        return res;
    }
    if (Bool *res = DoubleCompareOperatorTemplate(other, [](double l, double r) { return abs(l - r) >= EPS; })) {
        return res;
    }
    return new Bool(new bool(true));
}
