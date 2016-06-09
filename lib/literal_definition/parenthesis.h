#ifndef LO21_LITERAL_DEFINITION_PARENTHESIS_H
#define LO21_LITERAL_DEFINITION_PARENTHESIS_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/parenthesis.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

/**
 * Definition of an parethesis literal.
 */
class ParenthesisLiteralDefinition: public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\\(|\\)";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new ParenthesisLiteral(value));
    }

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<ParenthesisLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 12) == "parenthesis:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        ParenthesisLiteralPointer parenthesisLiteral = dynamic_pointer_cast<ParenthesisLiteral>(literal);
        return "parenthesis:" + parenthesisLiteral->getParenthesis();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(12));
    }
};


#endif // LO21_LITERAL_DEFINITION_PARENTHESIS_H
