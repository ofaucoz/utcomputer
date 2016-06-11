#ifndef LO21_OPERATOR_STACK_SWAP_H
#define LO21_OPERATOR_STACK_SWAP_H


#include "interface.h"
#include "../exception/invalid_syntax.h"

class StackSwapOperator: public OperatorInterface {
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


#endif // LO21_OPERATOR_STACK_SWAP_H
