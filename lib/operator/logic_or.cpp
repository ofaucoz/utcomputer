#include "logic_or.h"

void LogicOrOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("Or operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    int result = 1;

    if (first->toString() == "0" && second->toString() == "0") {
        result = 0;
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(result)));
}
