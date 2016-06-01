#include "runner.h"
#include "literal/expression.h"
#include "literal/numeric.h"
#include "literal/operator.h"
#include "exception/unspported_literal.h"

void Runner::run(LiteralVector tokens) {
    for (LiteralVector::iterator iterator = tokens.begin(); iterator != tokens.end(); ++iterator) {
        if (NumericLiteralPointer numericLiteral = dynamic_pointer_cast<NumericLiteral>(*iterator)) {
            // For each numeric, push it into the stack
            literalStack.pushAndNotify(numericLiteral);
        } else if (ExpressionLiteralPointer expressionLiteral = dynamic_pointer_cast<ExpressionLiteral>(*iterator)) {
            // For each expression, push it into the stack
            literalStack.pushAndNotify(expressionLiteral);
        } else if (OperatorLiteralPointer operatorLiteral = dynamic_pointer_cast<OperatorLiteral>(*iterator)) {
            // For each operator, execute it
            if (! operatorsMap.has(operatorLiteral->getName())) {
                throw "Operator not supported";
            }

            operatorsMap.get(operatorLiteral->getName())->apply(literalStack);
        } else {
            throw UnsupportedLiteralException((*iterator)->toString());
        }
    }
}
