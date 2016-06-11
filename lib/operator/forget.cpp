#include "forget.h"

void ForgetOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("STO operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    ExpressionLiteralPointer firstExpression = dynamic_pointer_cast<ExpressionLiteral>(first);

    if (!firstExpression) {
        throw InvalidOperandException(first->toString());
    }

    string expectedAtom = first->toString();

    expectedAtom.erase(remove(expectedAtom.begin(), expectedAtom.end(), '\''), expectedAtom.end());

    AtomLiteralDefinition definition;

    if (dynamic_pointer_cast<AtomLiteral>(definition.createInstance(expectedAtom)) == nullptr) {
        throw InvalidOperandException(firstExpression->toString());
    }
    if (variableMap.at(expectedAtom)) {
        variableMap.removeAndNotify(expectedAtom);
    }
    stack.notify();
}
