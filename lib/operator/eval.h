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
    UTComputer &computer;

    /**
     * Find the priority of the given operator by its name.
     * Fallback on a default 0 if the operator was not found.
     *
     * @param name The operator name.
     * @return The operator priority or 0.
     */
    int findPriority(string name) const;

public:
    /**
     * The eval operator executes an expression by using the UTComputer itself,
     * recursively. Therefore, it needs it to execute the expression.
     *
     * @param computer The UTComputer instance.
     */
    EvalOperator(UTComputer &computer) : computer(computer) { }

    /**
     * Postfix a given infix string using the computer literal definitions and the
     * computer operators.
     *
     * @param infix The string to postfix
     * @return A vector of literals corresponding to the postfixed version of the given string.
     */
    LiteralVector postfix(string infix) const;

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

#endif // LO21_OPERATOR_EVAL_H
