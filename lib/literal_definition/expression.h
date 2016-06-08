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
class ExpressionLiteralDefinition : public LiteralDefinitionInterface {
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
};


#endif // LO21_LITERAL_DEFINITION_EXPRESSION_H
