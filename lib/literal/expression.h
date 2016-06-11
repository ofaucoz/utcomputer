#ifndef LO21_LITERAL_EXPRESSION_H
#define LO21_LITERAL_EXPRESSION_H


#include "interface.h"

using namespace std;

/**
 * An expression literal represents a quoted expression that can be evaluated.
 * For instance :
 *      '3*X1+(3+TOTO)/-2'
 */
struct ExpressionLiteral: public LiteralInterface {
private:
    string value;

public:
    /**
     * @param value The expression.
     */
    ExpressionLiteral(string value) : value(value) { }

    /**
     * @return The expression.
     */
    const string &getValue() const {
        return value;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return value;
    };
};

typedef shared_ptr<ExpressionLiteral> ExpressionLiteralPointer;


#endif // LO21_LITERAL_EXPRESSION_H
