#include "numeric_lesser.h"

void NumericLesserOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Lesser operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    LiteralPointer second = stack.second();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (!firstNumeric) {
        throw InvalidOperandException(first->toString());
    }

    if (!secondNumeric) {
        throw InvalidOperandException(second->toString());
    }

    double firstModule = Math::module(firstNumeric->getRealFraction(), firstNumeric->getImaginaryFraction());
    double secondModule = Math::module(secondNumeric->getRealFraction(), secondNumeric->getImaginaryFraction());

    stack.pop();
    stack.pop();
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(firstModule > secondModule ? 1 : 0)));
    stack.save();
}
