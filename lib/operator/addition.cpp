#include "addition.h"

void AdditionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Addition operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    LiteralPointer second = stack.second();

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

    stack.pop();
    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(resultR, resultI)));
    stack.save();
}
