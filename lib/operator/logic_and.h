#ifndef LO21_OPERATOR_LOGIC_AND_H
#define LO21_OPERATOR_LOGIC_AND_H


#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"

using namespace std;

class LogicAndOperator: public OperatorInterface {
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


#endif //LO21_OPERATOR_LOGIC_AND_H
