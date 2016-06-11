#ifndef LO21_OPERATOR_STACK_CLEAR_OPERATOR_H
#define LO21_OPERATOR_STACK_CLEAR_OPERATOR_H


#include "../literal/interface.h"
#include "interface.h"
#include "../exception/invalid_syntax.h"

class StackClearOperator: public OperatorInterface {
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


#endif //LO21_OPERATOR_STACK_CLEAR_OPERATOR_H
