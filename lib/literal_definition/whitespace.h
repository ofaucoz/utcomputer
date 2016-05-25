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
    const string getPattern() const override {
        return "\\s+";
    }

    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new WhitespaceLiteral());
    }
};


#endif // LO21_LITERAL_DEFINITION_WHITESPACE_H
