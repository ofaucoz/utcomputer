#ifndef LO21_LITERAL_DEFINITION_OPERATOR_STRICT_H
#define LO21_LITERAL_DEFINITION_OPERATOR_STRICT_H

#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/operator.h"

using namespace std;

/**
 * Definition of a strict comparison operator literal.
 */
class OperatorStrictComparisonLiteralDefinition: public LiteralDefinitionInterface {
public:
    const string getPattern() const override {
        return "\\=|!\\=|>|<";
    }

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

#endif //LO21_LITERAL_DEFINITION_OPERATOR_STRICT_H
