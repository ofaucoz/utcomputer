#include "numerator.h"

void NumeratorOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("Numerator operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (firstNumeric->toString().find("$") != std::string::npos) {
        throw InvalidOperandException(first->toString());
    }

    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(firstNumeric->getRealNumerator())));
    stack.save();
}
