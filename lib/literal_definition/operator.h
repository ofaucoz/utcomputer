#ifndef LO21_LITERAL_DEFINITION_OPERATOR_H
#define LO21_LITERAL_DEFINITION_OPERATOR_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/operator.h"

using namespace std;

/*
 * Definition of an operator literal.
 */
class OperatorLiteralDefinition : public LiteralDefinitionInterface {
public:
    const string getPattern() const override {
        return "\\+|\\-|\\*|\\/|\\$";
    }

    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new OperatorLiteral(value));
    }
};


#endif // LO21_LITERAL_DEFINITION_OPERATOR_H
