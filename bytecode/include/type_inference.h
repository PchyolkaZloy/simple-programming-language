
#pragma once

#include "variables_util.h"
#include "operators.h"
#include <optional>
#include <memory>

namespace bytecode {


    class TypeInspector {
    public:
        [[nodiscard]] std::optional<std::unique_ptr<Type>>
        inferForBinaryOp(const Type &v1_type, const Type &v2_type, BinaryOperator op) const {
            if (!(v1_type.isPrimitive() && v2_type.isPrimitive()))
                return std::nullopt;
            const auto & v1_real_t = dynamic_cast<const PrimitiveType &>(v1_type);
            const auto & v2_real_t = dynamic_cast<const PrimitiveType &>(v2_type);
            switch (op) {
                case BinaryOperator::Mult:
                    break;
                case BinaryOperator::Div:
                    break;
                case BinaryOperator::Mod:
                    break;
                case BinaryOperator::Add:
                    break;
                case BinaryOperator::Sub:
                    break;
                case BinaryOperator::Eq:
                    break;
                case BinaryOperator::Neq:
                    break;
                case BinaryOperator::Lt:
                    break;
                case BinaryOperator::Gt:
                    break;
                case BinaryOperator::Le:
                    break;
                case BinaryOperator::Ge:
                    break;
                case BinaryOperator::And:
                    break;
                case BinaryOperator::Or:
                    break;
            }
        }

        [[nodiscard]] std::optional<std::unique_ptr<Type>> inferArrayAccess(const Type &v_type) const {
            if (!v_type.isArrayType())
                return {};
            std::unique_ptr<Type> new_type(v_type.clone());
            new_type->setArrayDepth(new_type->getArrayDepth() - 1);
            return new_type;
        }

        [[nodiscard]] std::optional<std::unique_ptr<Type>>
        inferFieldAccess(const std::string &field_name, const StructureSignature &structure) const {
//            changing nothing, honestly
            auto &st = const_cast<StructureSignature &>(structure);
            auto it = st.find(field_name);
            if (it == st.end())
                return {};
            return std::unique_ptr<Type>(it->second->clone());
        }

    };


}

