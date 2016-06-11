#ifndef LO21_LITERAL_DEFINITION_ATOM_H
#define LO21_LITERAL_DEFINITION_ATOM_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/atom.h"

using namespace std;

/**
 * Definition of an atom literal.
 */
class AtomLiteralDefinition: public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "[A-Z][A-Z0-9]+";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new AtomLiteral(value));
    }

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<AtomLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 5) == "atom:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        AtomLiteralPointer atomLiteral = dynamic_pointer_cast<AtomLiteral>(literal);
        return "atom:" + atomLiteral->getValue();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(5));
    }
};


#endif // LO21_LITERAL_DEFINITION_ATOM_H
