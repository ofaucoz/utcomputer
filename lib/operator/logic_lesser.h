#ifndef LO21_LOGIC_LESSER_H
#define LO21_LOGIC_LESSER_H


#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include <math.h>

using namespace std;

class LogicLesserOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;

    int getPriority() const {
        return 0;
    }
};



#endif //LO21_LOGIC_LESSER_H
