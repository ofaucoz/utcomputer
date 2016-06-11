#ifndef LO21_STO_H
#define LO21_STO_H

#include "interface.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"
#include "../lexer.h"

using namespace std;

class StoOperator : public OperatorInterface {
private:
    VariableMap &variableMap;
    ProgramMap &programMap;
    Lexer &lexer;
public:
    StoOperator(VariableMap & variableMap,ProgramMap &programMap,Lexer &lexer) : variableMap(variableMap), programMap(programMap), lexer(lexer) { }

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
