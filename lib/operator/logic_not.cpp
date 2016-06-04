#include "logic_not.h"


void LogicNotOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
         throw InvalidSyntaxException("Equals operator requires 2 operands");
    }
    int firstLogicalValue = 1;

    LiteralPointer first = stack.top();
    stack.pop();


    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);



    if(firstNumeric->toString()=="0"){
        firstLogicalValue = 0;
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(1-firstLogicalValue)));
}

