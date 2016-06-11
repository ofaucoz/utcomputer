#include "sto.h"
#include "../literal/atom.h"
#include "../literal_definition/atom.h"

void StoOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("STO operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
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

    variableMap.setAndNotify(expectedAtom, second);
    stack.notify();
}
