#include "stack_undo.h"

void StackUndoOperator::apply(LiteralsStack &stack) const {
    stack.undo();
    stack.notify();
}
