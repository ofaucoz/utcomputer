#include "stack_dup.h"


void StackDupOperator::apply(LiteralsStack &stack) const {
    if (stack.size() == 0) {
        throw InvalidSyntaxException("DUP operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    stack.pushAndNotify(first);
}
