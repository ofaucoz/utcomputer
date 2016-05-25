#ifndef LO21_LITERAL_DEFINITION_ATOM_H
#define LO21_LITERAL_DEFINITION_ATOM_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/atom.h"

using namespace std;

/*
 * Definition of an atom literal.
 */
class AtomLiteralDefinition : public LiteralDefinitionInterface {
public:
    const string getPattern() const override {
        return "[A-Z][A-Z0-9]+";
    }

    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new AtomLiteral(value));
    }
};


#endif // LO21_LITERAL_DEFINITION_ATOM_H
