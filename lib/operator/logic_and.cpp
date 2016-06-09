#include "logic_and.h"

void LogicAndOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("And operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    int result = 1;

    if (first->toString() == "0" || second->toString() == "0") {
        result = 0;
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(result)));
    stack.save();
}
