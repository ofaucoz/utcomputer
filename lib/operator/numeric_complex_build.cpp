#include "numeric_complex_build.h"

void NumericComplexBuildOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("ComplexBuilder operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (!firstNumeric) {
        stack.notify();
        throw InvalidOperandException(first->toString());
    }

    if (!secondNumeric) {
        stack.notify();
        throw InvalidOperandException(second->toString());
    }

    if (firstNumeric->getImaginaryNumerator() != 0 || secondNumeric->getImaginaryNumerator() != 0) {
        stack.notify();
        throw InvalidSyntaxException("Arguments can't already be complex");
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        secondNumeric->getRealNumerator(),
        secondNumeric->getRealDenominator(),
        firstNumeric->getRealNumerator(),
        firstNumeric->getRealDenominator()
    )));

    stack.save();
}

