#ifndef LO21_OPERATOR_MODULO_H
#define LO21_OPERATOR_MODULO_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class ModuloOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};

#endif // LO21_OPERATOR_MODULO_H
