#include "logic_lesser.h"


void LogicLesserOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Equals operator requires 2 operands");
    }
    double firstNumericModule = 0;
    double secondNumericModule = 0;
    int realNum = 0;
    int realDen = 0;
    int imagNum= 0;
    int imagDen = 0;

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (! firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (! secondNumeric) {
        throw InvalidOperandException(second->toString());
    }

    realNum = firstNumeric->getRealNumerator();
    realDen = firstNumeric->getRealDenominator();
    imagNum = firstNumeric->getImaginaryNumerator();
    imagDen = firstNumeric->getImaginaryDenominator();

    firstNumericModule =sqrt((pow(realNum,2) / pow(realDen,2))+(pow(imagNum,2) / pow(imagDen,2)));

    realNum = secondNumeric->getRealNumerator();
    realDen = secondNumeric->getRealDenominator();
    imagNum = secondNumeric->getImaginaryNumerator();
    imagDen = secondNumeric->getImaginaryDenominator();


    secondNumericModule =sqrt((pow(realNum,2) / pow(realDen,2))+(pow(imagNum,2) / pow(imagDen,2)));

    if(firstNumericModule > secondNumericModule){
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(1)));
    }
    else{
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(0)));
    }




}