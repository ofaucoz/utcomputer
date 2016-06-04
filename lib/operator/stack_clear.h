#ifndef LO21_STACK_CLEAR_OPERATOR_H
#define LO21_STACK_CLEAR_OPERATOR_H


#include "../literal/interface.h"
#include "interface.h"
#include "../exception/invalid_syntax.h"

class StackClearOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_STACK_CLEAR_OPERATOR_H
