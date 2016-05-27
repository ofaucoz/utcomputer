#ifndef LO21_OPERATOR_DIVISION_H
#define LO21_OPERATOR_DIVISION_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

class DivisionOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override {
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
            throw InvalidOperandException(first->toString());
        }

        if (! secondNumeric) {
            throw InvalidOperandException(second->toString());
        }

        if (secondNumeric->getRealNumerator() == 0 && secondNumeric->getImaginaryNumerator() == 0) {
            throw InvalidSyntaxException("Dividing by zero is not possible");
        }

        double resultRN = secondNumeric->getRealNumerator() * firstNumeric->getRealDenominator();
        double resultRD = secondNumeric->getRealDenominator() * firstNumeric->getRealNumerator();
        double resultIN = secondNumeric->getImaginaryNumerator() * firstNumeric->getImaginaryDenominator();
        double resultID = secondNumeric->getImaginaryDenominator() * firstNumeric->getImaginaryNumerator();

        if (resultRD == 0) {
            resultRD = 1;
        }

        if (resultID == 0) {
            resultID = 1;
        }

        stack.pushAndNotify(LiteralPointer(new NumericLiteral(
            Math::simplify(Fraction(resultRN, resultRD)),
            Math::simplify(Fraction(resultIN, resultID))
        )));
    }
};

#endif // LO21_OPERATOR_DIVISION_H
