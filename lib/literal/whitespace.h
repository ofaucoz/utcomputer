#ifndef LO21_LITERAL_WHITESPACE_H
#define LO21_LITERAL_WHITESPACE_H


#include "interface.h"

using namespace std;

/**
 * A whitespace literal.
 * For instance :
 *      a space or a tabulation
 */
struct WhitespaceLiteral: public LiteralInterface {
public:
    /**
     * @inheritdoc
     */
    const string toString() const override {
        return " ";
    };
};

typedef shared_ptr<WhitespaceLiteral> WhitespaceLiteralPointer;


#endif // LO21_LITERAL_WHITESPACE_H
