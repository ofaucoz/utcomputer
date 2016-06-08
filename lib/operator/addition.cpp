#include "addition.h"

void AdditionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Addition operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (!secondNumeric) {
        throw InvalidOperandException(second->toString());
    }

    Fraction resultR = Math::add(firstNumeric->getRealFraction(), secondNumeric->getRealFraction());
    Fraction resultI = Math::add(firstNumeric->getImaginaryFraction(), secondNumeric->getImaginaryFraction());

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(resultR, resultI)));
}
