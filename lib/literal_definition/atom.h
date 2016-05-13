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
    string getPattern() const {
        return "[A-Z][A-Z0-9]+";
    }

    LiteralInterface* createInstance(string value) const {
        return new AtomLiteral(value);
    }
};


#endif // LO21_LITERAL_DEFINITION_ATOM_H
