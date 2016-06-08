#include "logic_equals.h"


void LogicEqualsOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Equals operator requires 2 operands");
    }


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

    if(firstNumeric->toString()==secondNumeric->toString()){
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(1)));
    }else{
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(0)));
    }
}