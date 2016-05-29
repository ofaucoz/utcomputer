#include "substraction.h"

void SubstractionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Substraction operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (! firstNumeric) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(first->toString());
    }

    if (! secondNumeric) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(second->toString());
    }

    Fraction resultR = Math::substract(secondNumeric->getRealFraction(), firstNumeric->getRealFraction());
    Fraction resultI = Math::substract(secondNumeric->getImaginaryFraction(), firstNumeric->getImaginaryFraction());

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(resultR, resultI)));
}
