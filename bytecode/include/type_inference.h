
#pragma once

#include "variables_util.h"
#include "operators.h"
#include <memory>

namespace bytecode {


    class TypeInspector {
    public:
        [[nodiscard]] std::unique_ptr<Type>
        inferForBinaryOp(const Type &v1_type, const Type &v2_type, BinaryOperator op) const {
            Type *result;
            if (!(v1_type.isPrimitive() && v2_type.isPrimitive()))
                return {nullptr};
            if (v1_type.isArrayType() || v2_type.isArrayType())
                return {nullptr};
            switch (op) {
                case BinaryOperator::Mult:
                case BinaryOperator::Div:
                case BinaryOperator::Add:
                case BinaryOperator::Sub:
                    if (v1_type.getTypeValue() == "double" || v2_type.getTypeValue() == "double")
                        result = new PrimitiveType(PrimitiveTypeValue::Double, 0);
                    else
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    break;
                case BinaryOperator::Mod:
                    if (v1_type.getTypeValue() == "double" || v2_type.getTypeValue() == "double")
                        return {nullptr};
                    else
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    break;
                case BinaryOperator::Eq:
                case BinaryOperator::Neq:
                case BinaryOperator::Lt:
                case BinaryOperator::Gt:
                case BinaryOperator::Le:
                case BinaryOperator::Ge:
                case BinaryOperator::And:
                case BinaryOperator::Or:
                    result = new PrimitiveType(PrimitiveTypeValue::Bool, 0);
                    break;
            }
            return std::unique_ptr<Type>(result);
        }

        [[nodiscard]] std::unique_ptr<Type> inferForUnaryOp(const Type &v_type, UnaryOperator op) const {
            Type *result;
            if (!v_type.isPrimitive() || v_type.isArrayType())
                return {nullptr};
            switch (op) {
                case UnaryOperator::Minus:
                    if (v_type.getTypeValue() == "double")
                        result = new PrimitiveType(PrimitiveTypeValue::Double, 0);
                    else
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    break;
                case UnaryOperator::Not:
                    result = new PrimitiveType(PrimitiveTypeValue::Bool, 0);
                    break;
            }
        }

        [[nodiscard]] std::unique_ptr<Type> inferArrayAccess(const Type &v_type) const {
            if (!v_type.isArrayType())
                return {nullptr};
            std::unique_ptr<Type> new_type(v_type.clone());
            new_type->setArrayDepth(new_type->getArrayDepth() - 1);
            return new_type;
        }

        [[nodiscard]] std::unique_ptr<Type>
        inferFieldAccess(const std::string &field_name, const StructureSignature &structure) const {
//            changing nothing, honestly
            auto &st = const_cast<StructureSignature &>(structure);
            auto it = st.find(field_name);
            if (it == st.end())
                return {nullptr};
            return std::unique_ptr<Type>(it->second->clone());
        }

    };


}

