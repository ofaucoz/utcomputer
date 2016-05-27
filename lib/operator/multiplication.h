#ifndef LO21_OPERATOR_MULTIPLICATION_H
#define LO21_OPERATOR_MULTIPLICATION_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class MultiplicationOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};

#endif // LO21_OPERATOR_MULTIPLICATION_H
