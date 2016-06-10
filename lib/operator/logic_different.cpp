#include "logic_different.h"

void LogicDifferentOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Different operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    LiteralPointer second = stack.second();

    stack.pop();
    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(first->toString() == second->toString() ? 0 : 1)));
    stack.save();
}
