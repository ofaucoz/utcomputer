
#include "numeric_complex_build.h"



void NumericComplexBuildOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        if (stack.size() == 1) {
            stack.pop();
        }

        throw InvalidSyntaxException("ComplexBuilder operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (! firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (! secondNumeric) {
        throw InvalidOperandException(second->toString());
    }

    if (firstNumeric->getImaginaryNumerator() != 0 || secondNumeric->getImaginaryNumerator()!= 0) {
        throw InvalidSyntaxException("Arguments can't already be complex");
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(secondNumeric->getRealNumerator(),secondNumeric->getRealDenominator(),firstNumeric->getRealNumerator(),firstNumeric->getRealDenominator())));
}

