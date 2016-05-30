#ifndef LO21_OPERATOR_OPPOSITE_H
#define LO21_OPERATOR_OPPOSITE_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class OppositeOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};

#endif // LO21_OPERATOR_OPPOSITE_H