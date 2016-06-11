#ifndef LO21_LITERAL_COMMA_H
#define LO21_LITERAL_COMMA_H


#include "interface.h"

using namespace std;

/**
 * A comma literal represents a comma.
 * For instance :
 *      ,
 */
struct CommaLiteral: public LiteralInterface {
public:
    /**
     * @inheritdoc
     */
    const string toString() const override {
        return ",";
    };
};

typedef shared_ptr<CommaLiteral> CommaLiteralPointer;


#endif // LO21_LITERAL_COMMA_H
