#include "multiplication.h"

void MultiplicationOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Multiplication operator requires 2 operands");
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

    Fraction resultR(
        secondNumeric->getRealNumerator() * firstNumeric->getRealNumerator(),
        secondNumeric->getRealDenominator() * firstNumeric->getRealDenominator()
    );

    Fraction resultI(
        secondNumeric->getImaginaryNumerator() * firstNumeric->getImaginaryNumerator(),
        secondNumeric->getImaginaryDenominator() * firstNumeric->getImaginaryDenominator()
    );

    stack.pop();
    stack.pop();

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        Math::simplify(resultR),
        Math::simplify(resultI)
    )));

    stack.save();
}
