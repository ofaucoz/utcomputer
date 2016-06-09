#include "logic_lesser.h"

void LogicLesserOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Lesser operator requires 2 operands");
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

    double realNum, realDen, imagNum, imagDen, firstNumericModule, secondNumericModule;

    realNum = firstNumeric->getRealNumerator();
    realDen = firstNumeric->getRealDenominator();
    imagNum = firstNumeric->getImaginaryNumerator();
    imagDen = firstNumeric->getImaginaryDenominator();

    firstNumericModule = sqrt((pow(realNum, 2) / pow(realDen, 2)) + (pow(imagNum, 2) / pow(imagDen, 2)));

    realNum = secondNumeric->getRealNumerator();
    realDen = secondNumeric->getRealDenominator();
    imagNum = secondNumeric->getImaginaryNumerator();
    imagDen = secondNumeric->getImaginaryDenominator();

    secondNumericModule = sqrt((pow(realNum, 2) / pow(realDen, 2)) + (pow(imagNum, 2) / pow(imagDen, 2)));

    if (firstNumericModule > secondNumericModule) {
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(1)));
    } else {
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(0)));
    }
}
