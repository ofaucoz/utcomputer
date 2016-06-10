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
class OperatorStrictComparisonLiteralDefinition : public LiteralDefinitionInterface {
public:
    const string getPattern() const override {
        return "\\=|!\\=|>|<";
    }

    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new OperatorLiteral(value));
    }
};

#endif //LO21_LITERAL_DEFINITION_OPERATOR_STRICT_H
