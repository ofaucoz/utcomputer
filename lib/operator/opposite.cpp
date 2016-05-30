#include "opposite.h"

void OppositeOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("Opposite operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);

    if (! firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        -firstNumeric->getRealNumerator(),
        firstNumeric->getRealDenominator(),
        firstNumeric->getImaginaryNumerator(),
        firstNumeric->getImaginaryDenominator()
    )));
}
