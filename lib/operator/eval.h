#ifndef LO21_OPERATOR_EVAL_H
#define LO21_OPERATOR_EVAL_H


#include "interface.h"
#include "../utcomputer.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/expression.h"
#include "../literal_definition/program.h"
#include "../literal_definition/operator.h"
#include "../literal_definition/parenthesis.h"
#include "../literal_definition/comma.h"

using namespace std;

class EvalOperator : public OperatorInterface {
private:
    UTComputer& computer;
    int findPriority(string name) const;

public:
    EvalOperator(UTComputer &computer) : computer(computer) { }

    LiteralVector postfix(string infix) const;
    void apply(LiteralsStack& stack) const override;

    int getPriority() const override {
        return 0;
    }
};

#endif // LO21_OPERATOR_EVAL_H
