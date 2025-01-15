#pragma once

#include "variables_util.h"
#include "bytecodes.h"
#include <memory>

namespace bytecode {

    class TypeInspector {
    public:
        [[nodiscard]] std::shared_ptr<Type>
        inferForBinaryOp(const Type& v1_type, const Type& v2_type, BinaryOps op) const {
            Type* result;
            if (!(v1_type.isPrimitive() && v2_type.isPrimitive())) {
                return {nullptr};
            }
            if (v1_type.isArrayType() || v2_type.isArrayType()) {
                return {nullptr};
            }
            switch (op) {
                case BinaryOps::Mul:
                case BinaryOps::Div:
                case BinaryOps::Add:
                case BinaryOps::Sub:
                    if (v1_type.getTypeValue() == "double" || v2_type.getTypeValue() == "double") {
                        result = new PrimitiveType(PrimitiveTypeValue::Double, 0);
                    } else {
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    }
                    break;
                case BinaryOps::Mod:
                    if (v1_type.getTypeValue() == "double" || v2_type.getTypeValue() == "double") {
                        return {nullptr};
                    } else {
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    }
                    break;
                case BinaryOps::Eq:
                case BinaryOps::NotEq:
                case BinaryOps::Less:
                case BinaryOps::Gr:
                case BinaryOps::LessEq:
                case BinaryOps::GrEq:
                case BinaryOps::And:
                case BinaryOps::Or:
                    result = new PrimitiveType(PrimitiveTypeValue::Bool, 0);
                    break;
            }
            return std::shared_ptr<Type>(result);
        }

        [[nodiscard]] std::shared_ptr<Type> inferForUnaryOp(const Type& v_type, UnaryOps op) const {
            Type* result;
            if (!v_type.isPrimitive() || v_type.isArrayType()) {
                return {nullptr};
            }
            switch (op) {
                case UnaryOps::Minus:
                    if (v_type.getTypeValue() == "double") {
                        result = new PrimitiveType(PrimitiveTypeValue::Double, 0);
                    } else {
                        result = new PrimitiveType(PrimitiveTypeValue::Int, 0);
                    }
                    break;
                case UnaryOps::Not:
                    result = new PrimitiveType(PrimitiveTypeValue::Bool, 0);
                    break;
            }
            return std::shared_ptr<Type>(result);
        }

        [[nodiscard]] std::shared_ptr<Type> inferArrayAccess(const Type& v_type) const {
            if (!v_type.isArrayType()) {
                return {nullptr};
            }
            std::shared_ptr<Type> new_type(v_type.clone());
            new_type->setArrayDepth(new_type->getArrayDepth() - 1);
            return new_type;
        }

        [[nodiscard]] std::shared_ptr<Type>
        inferFieldAccess(const std::string& field_name, const StructureSignature& structure) const {
            // changing nothing, honestly
            auto& st = const_cast<StructureSignature&>(structure);
            auto it = st.find(field_name);
            if (it == st.end()) {
                return {nullptr};
            }
            return std::shared_ptr<Type>(it->second->clone());
        }
    };

} // namespace bytecode
