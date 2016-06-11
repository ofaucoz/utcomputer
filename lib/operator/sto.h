#ifndef LO21_STO_H
#define LO21_STO_H

#include "interface.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class StoOperator: public OperatorInterface {
private:
    VariableMap &variableMap;
public:
    StoOperator(VariableMap &variableMap) : variableMap(variableMap) { }
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const override {
        return 0;
    }
};

#endif //LO21_STO_H
