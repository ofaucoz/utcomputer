#include "modulo.h"

void ModuloOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Modulo operator requires 2 operands");
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

    if (firstNumeric->toString().find("/") != std::string::npos ||
        firstNumeric->toString().find("$") != std::string::npos ||
        firstNumeric->toString().find(".") != std::string::npos ||
        !Math::isInt(secondNumeric->getRealNumerator())) {
        throw InvalidOperandException(first->toString());
    }

    if (secondNumeric->toString().find("/") != std::string::npos ||
        secondNumeric->toString().find("$") != std::string::npos ||
        secondNumeric->toString().find(".") != std::string::npos ||
        !Math::isInt(secondNumeric->getRealNumerator())) {
        throw InvalidOperandException(second->toString());
    }

    stack.pop();
    stack.pop();

    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        (int) secondNumeric->getRealNumerator() % (int) firstNumeric->getRealNumerator()
    )));

    stack.save();
}
