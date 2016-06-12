#include "multiplication.h"

void MultiplicationOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Multiplication operator requires 2 operands");
    }

    LiteralPointer first = stack.second();
    LiteralPointer second = stack.top();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (!secondNumeric) {
        throw InvalidOperandException(second->toString());
    }
    Fraction firstRealPart(firstNumeric->getRealNumerator()*secondNumeric->getRealNumerator(),firstNumeric->getRealDenominator()*secondNumeric->getRealDenominator());
    Fraction secondRealPart(firstNumeric->getImaginaryNumerator()*secondNumeric->getImaginaryNumerator(),firstNumeric->getImaginaryDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction realPart = Math::substract(firstRealPart,secondRealPart);

    Fraction firstImaginaryPart(firstNumeric->getRealNumerator()*secondNumeric->getImaginaryNumerator(),firstNumeric->getRealDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction secondImaginaryPart(firstNumeric->getImaginaryNumerator()*secondNumeric->getRealNumerator(),firstNumeric->getImaginaryDenominator()*secondNumeric->getRealDenominator());
    Fraction imaginaryPart = Math::add(firstImaginaryPart,secondImaginaryPart);

    stack.pop();
    stack.pop();

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        Math::simplify(realPart),
        Math::simplify(imaginaryPart)
    )));

    stack.save();
}
