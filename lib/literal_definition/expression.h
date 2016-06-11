#ifndef LO21_LITERAL_DEFINITION_EXPRESSION_H
#define LO21_LITERAL_DEFINITION_EXPRESSION_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/expression.h"

using namespace std;

/**
 * Definition of an expression literal.
 */
class ExpressionLiteralDefinition: public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\'[^\']+\'";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new ExpressionLiteral(value));
    }

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<ExpressionLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 11) == "expression:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        ExpressionLiteralPointer expressionLiteral = dynamic_pointer_cast<ExpressionLiteral>(literal);
        return "expression:" + expressionLiteral->getValue();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(11));
    }
};


#endif // LO21_LITERAL_DEFINITION_EXPRESSION_H
