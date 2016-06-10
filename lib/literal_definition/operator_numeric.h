#ifndef LO21_LITERAL_DEFINITION_OPERATOR_NUMERIC_H
#define LO21_LITERAL_DEFINITION_OPERATOR_NUMERIC_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/operator.h"

using namespace std;

/**
 * Definition of a numeric operator literal.
 */
class OperatorNumericLiteralDefinition : public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\\+|\\-|\\*|\\/|\\$";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new OperatorLiteral(value));
    }
};


#endif // LO21_LITERAL_DEFINITION_OPERATOR_NUMERIC_H
