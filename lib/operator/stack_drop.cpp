#include "stack_drop.h"


void StackDropOperator::apply(LiteralsStack &stack) const {
    if (stack.size() == 0) {
        throw InvalidSyntaxException("Stack already cleared");
    }
    stack.popAndNotify();
}
