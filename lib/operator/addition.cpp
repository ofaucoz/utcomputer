#include "addition.h"

void AdditionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Addition operator requires 2 operands");
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

    Fraction resultR = Math::add(firstNumeric->getRealFraction(), secondNumeric->getRealFraction());
    Fraction resultI = Math::add(firstNumeric->getImaginaryFraction(), secondNumeric->getImaginaryFraction());

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(resultR, resultI)));
}
