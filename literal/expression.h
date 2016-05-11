#ifndef LO21_LITERAL_EXPRESSION_H
#define LO21_LITERAL_EXPRESSION_H


#include "literal_interface.h"

/*
 * An expression literal represents a quoted expression that can be evaluated.
 * For instance :
 *      '3*X1+(3+TOTO)/-2'
 */
struct ExpressionLiteral : public NumericLiteralInterface {
private:
    std::string value;

public:
    ExpressionLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }

    std::string getName() const {
        return "expression";
    };

    std::string toString() const {
        return value;
    };
};


#endif // LO21_LITERAL_EXPRESSION_H
