#ifndef LO21_OPERATOR_SUBSTRACTION_H
#define LO21_OPERATOR_SUBSTRACTION_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class SubstractionOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;

    int getPriority() const override {
        return 0;
    }
};

#endif // LO21_OPERATOR_SUBSTRACTION_H
