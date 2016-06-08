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
class ParenthesisLiteralDefinition : public LiteralDefinitionInterface {
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
};


#endif // LO21_LITERAL_DEFINITION_PARENTHESIS_H
