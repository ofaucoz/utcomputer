#include "logic_not.h"

void LogicNotOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("Not operator requires 1 operand");
    }

    LiteralPointer first = stack.top();

    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(first->toString() == "0" ? 1 : 0)));
    stack.save();
}

