#include "euclidian_division.h"

void EuclidianDivisionOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 2) {
        throw InvalidSyntaxException("Division operator requires 2 operands");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    LiteralPointer second = stack.top();
    stack.pop();

    NumericLiteralPointer firstNumeric = dynamic_pointer_cast<NumericLiteral>(first);
    NumericLiteralPointer secondNumeric = dynamic_pointer_cast<NumericLiteral>(second);

    if (! firstNumeric) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(first->toString());
    }

    if (! secondNumeric) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(second->toString());
    }

    if (firstNumeric->toString().find("/") != std::string::npos ||
        firstNumeric->toString().find("$") != std::string::npos ||
        ! Math::isInt(secondNumeric->getRealNumerator())) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(first->toString());
    }

    if (secondNumeric->toString().find("/") != std::string::npos ||
        secondNumeric->toString().find("$") != std::string::npos ||
        ! Math::isInt(secondNumeric->getRealNumerator())) {
        stack.push(second);
        stack.push(first);

        throw InvalidOperandException(second->toString());
    }
    
    stack.pushAndNotify(LiteralPointer(new NumericLiteral(
        (((int) secondNumeric->getRealNumerator()) / (int) firstNumeric->getRealNumerator()))
    ));
}
