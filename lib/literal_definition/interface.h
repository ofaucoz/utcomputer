#ifndef LO21_LITERAL_DEFINITION_INTERFACE_H
#define LO21_LITERAL_DEFINITION_INTERFACE_H


#include <iostream>
#include <regex>
#include "../literal/interface.h"

using namespace std;

/*
 * Interface for all literal definitions.
 *
 * A literal definition is an object associated to the creation of a given type of literal.
 * This definitions system let the developer to add custom literals to the lexer.
 */
class LiteralDefinitionInterface {
public:
    virtual string getPattern() const = 0;
    virtual LiteralInterface* createInstance(string value) const = 0;
};


#endif // LO21_LITERAL_DEFINITION_INTERFACE_H
