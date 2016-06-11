#include "division.h"

void DivisionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Division operator requires 2 operands");
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

    if (secondNumeric->getRealNumerator() == 0 && secondNumeric->getImaginaryNumerator() == 0) {
        throw InvalidSyntaxException("Dividing by zero is not possible");
    }

    Fraction firstRealPartNum(firstNumeric->getRealNumerator()*secondNumeric->getRealNumerator(),firstNumeric->getRealDenominator()*secondNumeric->getRealDenominator());
    Fraction secondRealPartNum(firstNumeric->getImaginaryNumerator()*secondNumeric->getImaginaryNumerator(),firstNumeric->getImaginaryDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction realPartNum = Math::add(firstRealPartNum,secondRealPartNum);
    Fraction firstRealPartDen(secondNumeric->getRealNumerator()*secondNumeric->getRealNumerator(),secondNumeric->getRealDenominator()*secondNumeric->getRealDenominator());
    Fraction secondRealPartDen(secondNumeric->getImaginaryNumerator()*secondNumeric->getImaginaryNumerator(),secondNumeric->getImaginaryDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction realPartDen = Math::add(firstRealPartDen,secondRealPartDen);
    Fraction realPart = Math::simplify(Fraction(realPartNum.getNumerator()*realPartDen.getDenominator(),realPartNum.getDenominator()*realPartDen.getNumerator()));

    Fraction firstImaginaryPartNum(firstNumeric->getImaginaryNumerator()*secondNumeric->getRealNumerator(),firstNumeric->getImaginaryDenominator()*secondNumeric->getRealDenominator());
    Fraction secondImaginaryPartNum(firstNumeric->getRealNumerator()*secondNumeric->getImaginaryNumerator(),firstNumeric->getRealDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction imaginaryPartNum = Math::substract(firstImaginaryPartNum,secondImaginaryPartNum);
    Fraction firstImaginaryPartDen(secondNumeric->getRealNumerator()*secondNumeric->getRealNumerator(),secondNumeric->getRealDenominator()*secondNumeric->getRealDenominator());
    Fraction secondImaginaryPartDen(secondNumeric->getImaginaryNumerator()*secondNumeric->getImaginaryNumerator(),secondNumeric->getImaginaryDenominator()*secondNumeric->getImaginaryDenominator());
    Fraction imaginaryPartDen = Math::add(firstImaginaryPartDen,secondImaginaryPartDen);
    Fraction imaginaryPart = Math::simplify(Fraction(imaginaryPartNum.getNumerator()*imaginaryPartDen.getDenominator(),imaginaryPartNum.getDenominator()*imaginaryPartDen.getNumerator()));

    stack.pop();
    stack.pop();

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        Math::simplify(realPart),
        Math::simplify(imaginaryPart)
    )));

    stack.save();
}
