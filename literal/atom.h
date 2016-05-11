#ifndef LO21_LITERAL_ATOM_H
#define LO21_LITERAL_ATOM_H


#include "literal_interface.h"

/*
 * An atom literal represents a name (for avariable of a program for example).
 * For instance :
 *      MYVAR
 */
struct AtomLiteral : public LiteralInterface {
private:
    std::string value;

public:
    AtomLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }

    std::string toString() const {
        return value;
    };
};


#endif // LO21_LITERAL_ATOM_H
