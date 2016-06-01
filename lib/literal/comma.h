#ifndef LO21_LITERAL_COMMA_H
#define LO21_LITERAL_COMMA_H


#include "interface.h"

using namespace std;

/*
 * A comma literal.
 */
struct CommaLiteral : public LiteralInterface {
public:
    const string toString() const override {
        return ",";
    };
};

/*
 * Comma literal pointer
 */
typedef shared_ptr<CommaLiteral> CommaLiteralPointer;


#endif // LO21_LITERAL_COMMA_H
