#ifndef LO21_LITERAL_PARENTHESIS_H
#define LO21_LITERAL_PARENTHESIS_H


#include "interface.h"

using namespace std;

/*
 * A parenthesis literal.
 */
struct ParenthesisLiteral : public LiteralInterface {
private:
    string value;

public:
    ParenthesisLiteral(string value) : value(value) { }

    const string &getValue() const {
        return value;
    }

    const string toString() const override {
        return value;
    };
};

/*
 * Whitespace literal pointer
 */
typedef shared_ptr<ParenthesisLiteral> ParenthesisLiteralPointer;


#endif // LO21_LITERAL_WHITESPACE_H
