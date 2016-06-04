#include "logic_and.h"


void LogicAndOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Equals operator requires 2 operands");
    }
    int result=1;

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    if(first->toString()=="0"||second->toString()=="0"){
        result = 0;
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(result)));
}