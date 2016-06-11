#ifndef LO21_OPERATOR_ATOM_LITERAL_H
#define LO21_OPERATOR_ATOM_LITERAL_H

#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/operator.h"

using namespace std;

/**
 * Definition of a custom operator literal.
 */
class OperatorAtomLiteralDefinition: public LiteralDefinitionInterface {
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
        return LiteralPointer(new OperatorLiteral(value));
    }

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return false; // Handled by the OperatorNumericLiteralDefinition
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return false; // Handled by the OperatorNumericLiteralDefinition
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        return ""; // Handled by the OperatorNumericLiteralDefinition
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return nullptr; // Handled by the OperatorNumericLiteralDefinition
    }
};

#endif //LO21_OPERATOR_ATOM_LITERAL_H
