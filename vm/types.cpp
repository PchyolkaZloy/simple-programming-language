#include "types.h"

gc::GarbageCollector gc::gc(false);
gc::Ref<Bool> BaseType::FALSE = gc::gc.create(new Bool(false));
gc::Ref<Bool> BaseType::TRUE = gc::gc.create(new Bool(true));


/// Int

gc::Ref<BaseType> Int::IntOperatorTemplate(const BaseType& other, IntType (*op)(const IntType&, const IntType&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int) {
        IntType l = IntCast();
        IntType r = other.IntCast();
        return gc::gc.create(new Int(op(l, r)));
    }
    return {};
}

gc::Ref<BaseType> Int::BoolOperatorTemplate(const BaseType& other, IntType (*op)(const IntType&, const IntType&)) const {
    if (other.Type != TypeIndex::Struct) { // struct is the only type not castable to bool
        BoolType l = BoolCast();
        BoolType r = other.BoolCast();
        return gc::gc.create(new Int(op(l, r)));
    }
    return {};
}

gc::Ref<BaseType> Int::DoubleOperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return gc::gc.create(new Double(op(l, r)));
    }
    return nullptr;
}

gc::Ref<BaseType> Int::operator%(const BaseType& other) const {
    if (auto res = IntOperatorTemplate(other, [](const IntType& l, const IntType& r) { return IntType(l % r); })) {
        return res;
    }
    throw std::invalid_argument(std::string("invalid operator ") + "%" + "\n");
}

#define DefIntOperator(op)                                                                                                             \
    gc::Ref<BaseType> Int::operator op(const BaseType & other) const {                                                 \
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

gc::Ref<Bool> Int::IntCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const IntType&, const IntType&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int) {
        IntType l = IntCast();
        IntType r = other.IntCast();
        return op(l, r) ? TRUE : FALSE;
    }
    return nullptr;
}

gc::Ref<Bool> Int::DoubleCompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return op(l, r) ? TRUE : FALSE;
    }
    return nullptr;
}

gc::Ref<Bool> Int::operator==(const BaseType& other) const {
    if (auto res = IntCompareOperatorTemplate(other, [](const IntType& l, const IntType& r) { return l == r; })) {
        return res;
    }
    if (auto res = DoubleCompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) < EPS; })) {
        return res;
    }
    return FALSE;
}

gc::Ref<Bool> Int::operator!=(const BaseType& other) const {
    if (auto res = IntCompareOperatorTemplate(other, [](const IntType& l, const IntType& r) { return l != r; })) {
        return res;
    }
    if (auto res = DoubleCompareOperatorTemplate(other, [](const DoubleType& l, const DoubleType& r) { return abs(l - r) >= EPS; })) {
        return res;
    }
    return TRUE;
}

#define DefIntCompareOperator(op)                                                                                               \
    gc::Ref<Bool> Int::operator op(const BaseType & other) const {                                                      \
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

gc::Ref<Bool> Double::CompareOperatorTemplate(const BaseType& other, BoolType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int ||
        other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return op(l, r) ? TRUE : FALSE;
    }
    return nullptr;
}

gc::Ref<BaseType> Double::OperatorTemplate(const BaseType& other, DoubleType (*op)(const DoubleType&, const DoubleType&)) const {
    if (other.Type == TypeIndex::Bool ||
        other.Type == TypeIndex::Char ||
        other.Type == TypeIndex::Int ||
        other.Type == TypeIndex::Double) {
        DoubleType l = DoubleCast();
        DoubleType r = other.DoubleCast();
        return gc::gc.create(new Double(op(l, r)));
    }
    return nullptr;
}

/// Array

gc::Ref<Bool> Array::CompareOperatorTemplate(
    const BaseType& other,
    BoolType (*op)(const gc::Ref<BaseType>&, const gc::Ref<BaseType>&)) const {
    const Array& arr = static_cast<const Array&>(other);
    if (other.Type != TypeIndex::Array || Size() != arr.Size()) {
        return FALSE;
    }
    const ValueType& l = GetArray();
    const ValueType& r = arr.GetArray();
    auto it1 = l.begin();
    auto it2 = r.begin();
    while (it1 != l.end()) {
        if (!op(*it1, *it2)) {
            return FALSE;
        }
    }

    return TRUE;
}

gc::Ref<BaseType> Array::operator+(const BaseType& other) const {
    const Array& arr = static_cast<const Array&>(other);
    if (other.Type != TypeIndex::Array) {
        throw std::invalid_argument("array can be added only with another array of the same type\n");
    }
    const ValueType& l = GetArray();
    const ValueType& r = arr.GetArray();
    gc::Ref<Array> res;
    std::copy(l.begin(), l.end(), std::back_inserter(res.object().GetArray()));
    std::copy(r.begin(), r.end(), std::back_inserter(res.object().GetArray()));
    return res;
}