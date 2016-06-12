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
class OperatorNumericLiteralDefinition: public LiteralDefinitionInterface {
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

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<OperatorLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 9) == "operator:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        OperatorLiteralPointer operatorLiteral = dynamic_pointer_cast<OperatorLiteral>(literal);
        return "operator:" + operatorLiteral->getName();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(9));
    }
};

#endif // LO21_LITERAL_DEFINITION_OPERATOR_NUMERIC_H
