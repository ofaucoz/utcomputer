#ifndef LO21_LITERAL_WHITESPACE_H
#define LO21_LITERAL_WHITESPACE_H


#include "interface.h"

using namespace std;

/*
 * A whitespace literal.
 */
struct WhitespaceLiteral : public LiteralInterface {
public:
    const string toString() const override {
        return " ";
    };
};

/*
 * Whitespace literal pointer
 */
typedef shared_ptr<WhitespaceLiteral> WhitespaceLiteralPointer;


#endif // LO21_LITERAL_WHITESPACE_H
