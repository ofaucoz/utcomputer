#ifndef LO21_LITERAL_INT_H
#define LO21_LITERAL_INT_H


#include "interface.h"

using namespace std;

/*
 * An operator literal represents an operator name.
 * For instance :
 *      +
 */
struct OperatorLiteral : public LiteralInterface {
private:
    string name;

public:
    OperatorLiteral(string value): name(value) {}

    const string &getName() const {
        return name;
    }

    const string toString() const override {
        return name;
    };
};


#endif // LO21_LITERAL_INT_H
