#include "types.h"

/// Int

std::shared_ptr<BaseType> Int::IntOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int) {
        IntType l = IntCast();
        IntType r = other.IntCast();
        return std::make_shared<Int>(new IntType(op(l, r)));
    }
    return {};
}

std::shared_ptr<BaseType> Int::BoolOperatorTemplate(const BaseType& other, cpp_int (*op)(const cpp_int&, const cpp_int&)) const {
    if (other.Type != TypeIndex::Struct) { // struct is the only type not castable to bool
        BoolType l = BoolCast();
        BoolType r = other.BoolCast();
        return std::make_shared<Bool>(new BoolType(op(l, r)));
    }
    return {};
}

std::shared_ptr<BaseType> Int::DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return std::make_shared<Double>(new DoubleType(op(l, r)));
    }
    return nullptr;
}

std::shared_ptr<BaseType> Int::operator%(const BaseType& other) const {
    if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) { return IntType(l % r); })) {
        return res;
    }
    throw std::invalid_argument(std::string("invalid operator ") + "%" + "\n");
}

#define DefIntOperator(op)                                                                                                             \
    std::shared_ptr<BaseType> Int::operator op(const BaseType & other) const {                                                         \
        if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) -> IntType { return l op r; })) {             \
            return res;                                                                                                                \
        }                                                                                                                              \
        if (auto res = DoubleOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) -> DoubleType { return l op r; })) { \
            return res;                                                                                                                \
        }                                                                                                                              \
        throw std::invalid_argument(std::string("invalid operator ") + #op + "\n");                                                    \
    }

DefIntOperator(+);
DefIntOperator(-);
DefIntOperator(*);
DefIntOperator(/);

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

#define DefIntCompareOperator(op)                                                                                               \
    std::shared_ptr<Bool> Int::operator op(const BaseType & other) const {                                                      \
        if (auto res = IntCompareOperatorTemplate(other, [](const IntType& l, const IntType& r) { return l op r; })) {          \
            return res;                                                                                                         \
        }                                                                                                                       \
        if (auto res = DoubleCompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return l op r; })) { \
            return res;                                                                                                         \
        }                                                                                                                       \
        throw std::invalid_argument(std::string("invalid operator ") + #op + "\n");                                             \
    }

DefIntCompareOperator(>);
DefIntCompareOperator(<);
DefIntCompareOperator(>=);
DefIntCompareOperator(<=);

/// Double

std::shared_ptr<Bool> Double::CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const {
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

std::shared_ptr<BaseType> Double::OperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
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

/// Array

std::shared_ptr<Bool> Array::CompareOperatorTemplate(
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

std::shared_ptr<BaseType> Array::operator+(const BaseType& other) const {
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