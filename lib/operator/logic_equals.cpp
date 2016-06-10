#include "logic_equals.h"

void LogicEqualsOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Equals operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    LiteralPointer second = stack.second();

    stack.pop();
    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(first->toString() == second->toString() ? 1 : 0)));
    stack.save();
}
