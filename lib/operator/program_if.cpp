#include "program_if.h"
#include "../literal/program.h"
#include "../literal/expression.h"
#include "../literal/operator.h"

void ProgramIfOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("If operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    if(second->toString()!="0"&&second->toString()!="1")
    {
        throw InvalidOperandException(second->toString());
    }

    ProgramLiteralPointer firstProgram = dynamic_pointer_cast<ProgramLiteral>(first);
    ExpressionLiteralPointer firstExpression = dynamic_pointer_cast<ExpressionLiteral>(first);

    if(!firstProgram&&!firstExpression)
    {
        throw InvalidOperandException(first->toString());
    }
    if(second->toString()=="1") {
        stack.pushAndNotify(first);
        evalOperator.apply(stack);
    }
}
