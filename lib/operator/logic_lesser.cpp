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

    firstNumericModule =sqrt((pow(firstNumeric->getRealNumerator(),2) / pow(firstNumeric->getRealDenominator(),2))
                             +
                             (pow(firstNumeric->getImaginaryNumerator(),2) / pow(firstNumeric->getImaginaryDenominator(),2)));


    secondNumericModule =sqrt((pow(secondNumeric->getRealNumerator(),2) / pow(secondNumeric->getRealDenominator(),2))
                              +
                              (pow(secondNumeric->getImaginaryNumerator(),2) / pow(secondNumeric->getImaginaryDenominator(),2)));
    if(firstNumericModule > secondNumericModule){
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(1)));
    }
    else{
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(0)));
    }




}