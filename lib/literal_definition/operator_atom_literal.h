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
class OperatorAtomLiteralDefinition : public LiteralDefinitionInterface {
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
};

#endif //LO21_OPERATOR_ATOM_LITERAL_H
