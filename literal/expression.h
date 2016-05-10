#ifndef LO21_LITERAL_EXPRESSION_H
#define LO21_LITERAL_EXPRESSION_H


#include "literal_interface.h"

struct ExpressionLiteral : public NumericLiteralInterface {
private:
    std::string value;

public:
    ExpressionLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }
};


#endif // LO21_LITERAL_EXPRESSION_H
