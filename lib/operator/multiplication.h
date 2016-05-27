#ifndef LO21_OPERATOR_MULTIPLICATION_H
#define LO21_OPERATOR_MULTIPLICATION_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class MultiplicationOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override {
        if (stack.size() < 2) {
            throw InvalidSyntaxException("Multiplication operator requires 2 operands");
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

        Fraction resultR(
            secondNumeric->getRealNumerator() * firstNumeric->getRealNumerator(),
            secondNumeric->getRealDenominator() * firstNumeric->getRealDenominator()
        );

        Fraction resultI(
            secondNumeric->getImaginaryNumerator() * firstNumeric->getImaginaryNumerator(),
            secondNumeric->getImaginaryDenominator() * firstNumeric->getImaginaryDenominator()
        );

        stack.pushAndNotify(LiteralPointer(new NumericLiteral(
            Math::simplify(resultR),
            Math::simplify(resultI)
        )));
    }
};

#endif // LO21_OPERATOR_MULTIPLICATION_H
