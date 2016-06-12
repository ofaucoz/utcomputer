#ifndef LO21_PROGRAM_IF_H
#define LO21_PROGRAM_IF_H


#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"
#include "eval.h"

using namespace std;

class ProgramIfOperator : public OperatorInterface {
private:
    EvalOperator &evalOperator;
public:
    ProgramIfOperator(EvalOperator &evalOperator) : evalOperator(evalOperator) { }
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const {
        return 0;
    }
};


#endif //LO21_PROGRAM_IF_H
