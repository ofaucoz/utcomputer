#include "stack_redo.h"

void StackRedoOperator::apply(LiteralsStack &stack) const {
    stack.redo();
    stack.notify();
}
