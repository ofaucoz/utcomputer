#ifndef LO21_LITERAL_OPERATOR_H
#define LO21_LITERAL_OPERATOR_H


#include "interface.h"

using namespace std;

/**
 * An operator literal represents a native operator or a custom resolved operator.
 * For instance :
 *      + (native) or DIV (custom)
 */
struct OperatorLiteral: public LiteralInterface {
private:
    string name;

public:
    /**
     * @param name The operator name.
     */
    OperatorLiteral(string name) : name(name) { }

    /**
     * @return The operator name.
     */
    const string &getName() const {
        return name;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return name;
    };
};

typedef shared_ptr<OperatorLiteral> OperatorLiteralPointer;


#endif // LO21_LITERAL_OPERATOR_H
