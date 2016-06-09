#include "logic_different.h"

void LogicDifferentOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Different operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (!secondNumeric) {
        throw InvalidOperandException(second->toString());
    }

    if (firstNumeric->toString() == secondNumeric->toString()) {
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(0)));
    } else {
        stack.pushAndNotify(LiteralPointer(new NumericLiteral(1)));
    }

    stack.save();
}
