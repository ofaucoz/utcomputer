#ifndef LO21_LITERAL_DEFINITION_COMMA_H
#define LO21_LITERAL_DEFINITION_COMMA_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/comma.h"

using namespace std;

/**
 * Definition of a comma literal.
 */
class CommaLiteralDefinition : public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return ",";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new CommaLiteral());
    }
};


#endif // LO21_LITERAL_DEFINITION_COMMA_H
