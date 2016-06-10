#include "stack_swap.h"

void StackSwapOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Swap operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    stack.push(first);
    stack.push(second);
    stack.notify();
    stack.save();
}
