#ifndef LO21_LITERAL_ATOM_H
#define LO21_LITERAL_ATOM_H


#include "interface.h"

using namespace std;

/*
 * An atom literal represents a name of a custom operator, a variable or a program.
 * For instance :
 *      MYVAR
 */
struct AtomLiteral : public LiteralInterface {
private:
    string value;

public:
    AtomLiteral(string value): value(value) {}

    const string &getValue() const {
        return value;
    }

    string toString() const {
        return value;
    };
};


#endif // LO21_LITERAL_ATOM_H
