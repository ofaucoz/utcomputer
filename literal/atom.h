#ifndef LO21_LITERAL_ATOM_H
#define LO21_LITERAL_ATOM_H


#include "interface.h"

struct AtomLiteral : public LiteralInterface {
private:
    std::string value;

public:
    AtomLiteral(std::string value): value(value) {}

    const std::string &getValue() const {
        return value;
    }
};


#endif // LO21_LITERAL_ATOM_H
