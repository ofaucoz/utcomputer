#include "stack_clear.h"

void StackClearOperator::apply(LiteralsStack &stack) const {
    if (stack.size() == 0) {
        throw InvalidSyntaxException("Stack already cleared");
    }
    while (stack.size() != 0) {
        stack.pop();
    }
}
