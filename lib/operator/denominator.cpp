#include "denominator.h"

void DenominatorOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("Denominator operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (firstNumeric->toString().find("$") != std::string::npos) {
        throw InvalidOperandException(first->toString());
    }

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(firstNumeric->getRealDenominator())));
}
