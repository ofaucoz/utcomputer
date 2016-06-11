#ifndef LO21_FORGET_H
#define LO21_FORGET_H

#include "interface.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"
#include "../literal/atom.h"
#include "../literal_definition/atom.h"

using namespace std;

class ForgetOperator: public OperatorInterface {
private:
    VariableMap &variableMap;
public:
    ForgetOperator(VariableMap &variableMap) : variableMap(variableMap) { }
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

#endif //LO21_FORGET_H
