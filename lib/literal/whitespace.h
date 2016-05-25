#ifndef LO21_LITERAL_WHITESPACE_H
#define LO21_LITERAL_WHITESPACE_H


#include "interface.h"

using namespace std;

/*
 * A numeric literal storing all possible types of numeric values.
 * For instance :
 *      1.4$3/4
 */
struct WhitespaceLiteral : public LiteralInterface {
public:
    const string toString() const override {
        return " ";
    };
};


#endif // LO21_LITERAL_WHITESPACE_H
