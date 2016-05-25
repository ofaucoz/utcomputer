#ifndef LO21_OPERATOR_PLUS_H
#define LO21_OPERATOR_PLUS_H


#include "interface.h"
#include "../math/math.h"
#include "../literal/numeric.h"
#include "../literal/expression.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

/*
 * Addition operator using the "+" symbol.
 */
class PlusOperator : public OperatorInterface {
public:
    const string getTokenValue() const override {
        return "+";
    }

    void apply(LiteralsStack& stack) const override {
        if (stack.size() < 2) {
            throw InvalidSyntaxException("+ operator requires 2 operands");
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

        Fraction resultR = Math::add(firstNumeric->getRealFraction(), secondNumeric->getRealFraction());
        Fraction resultI = Math::add(firstNumeric->getImaginaryFraction(), secondNumeric->getImaginaryFraction());

        stack.pushAndNotify(LiteralPointer(new NumericLiteral(resultR, resultI)));
    }
};

#endif // LO21_OPERATOR_PLUS_H
