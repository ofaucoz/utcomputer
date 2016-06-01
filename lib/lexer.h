#ifndef LO21_LEXER_H
#define LO21_LEXER_H


#include <iostream>
#include <vector>
#include <regex>
#include "literal/interface.h"
#include "literal_definition/interface.h"
#include "exception/invalid_syntax.h"

using namespace std;

/*
 * The lexer splits a given command into a list of literals using literal definitions
 * and pattern matching.
 */
class Lexer {
private:
    LiteralDefinitionVector definitions;

public:
    void addDefinition(LiteralDefinitionInterface* definition) {
        definitions.push_back(LiteralDefinitionPointer(definition));
    }

    void addDefinition(LiteralDefinitionPointer definition) {
        definitions.push_back(definition);
    }

    const LiteralDefinitionVector &getDefinitions() const {
        return definitions;
    }

    LiteralVector tokenize(string command) const;
};


#endif // LO21_LEXER_H
