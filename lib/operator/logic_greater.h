#ifndef LO21_LOGIC_GREATER_H
#define LO21_LOGIC_GREATER_H

#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include <math.h>

using namespace std;

class LogicGreaterOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_LOGIC_GREATER_H
