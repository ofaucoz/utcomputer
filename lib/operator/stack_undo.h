#ifndef LO21_STACK_UNDO_OPERATOR_H
#define LO21_STACK_UNDO_OPERATOR_H


#include "interface.h"
#include "../exception/invalid_syntax.h"

class StackUndoOperator : public OperatorInterface {
public:
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const {
        return 0;
    }
};


#endif //LO21_STACK_UNDO_OPERATOR_H
