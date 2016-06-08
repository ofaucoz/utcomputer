//
// Created by orphee on 04/06/16.
//

#ifndef LO21_STACK_DROP_OPERATOR_H
#define LO21_STACK_DROP_OPERATOR_H


#include "interface.h"
#include "../exception/invalid_syntax.h"

class StackDropOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;

    int getPriority() const {
        return 0;
    }
};



#endif //LO21_STACK_DROP_OPERATOR_H
