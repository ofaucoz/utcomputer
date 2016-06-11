#ifndef LO21_LITERAL_DEFINITION_WHITESPACE_H
#define LO21_LITERAL_DEFINITION_WHITESPACE_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/whitespace.h"

using namespace std;

/**
 * Definition of an whitespace literal.
 */
class WhitespaceLiteralDefinition: public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\\s+";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new WhitespaceLiteral());
    }

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<WhitespaceLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized == "whitespace";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        return "whitespace";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return LiteralPointer(new WhitespaceLiteral());
    }
};


#endif // LO21_LITERAL_DEFINITION_WHITESPACE_H
