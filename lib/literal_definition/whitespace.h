#ifndef LO21_LITERAL_DEFINITION_WHITESPACE_H
#define LO21_LITERAL_DEFINITION_WHITESPACE_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/whitespace.h"

using namespace std;

/*
 * Definition of an whitespace literal.
 */
class WhitespaceLiteralDefinition : public LiteralDefinitionInterface {
public:
    string getPattern() const {
        return "\\s+";
    }

    LiteralInterface* createInstance(string value) const {
        return new WhitespaceLiteral();
    }
};


#endif // LO21_LITERAL_DEFINITION_WHITESPACE_H
