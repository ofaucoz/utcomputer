#ifndef LO21_LOGIC_EQUALS_H
#define LO21_LOGIC_EQUALS_H


#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"

using namespace std;

class LogicEqualsOperator : public OperatorInterface {
public:
    void apply(LiteralsStack &stack) const override;

    int getPriority() const {
        return 0;
    }
};


#endif //LO21_LOGIC_EQUALS_H
