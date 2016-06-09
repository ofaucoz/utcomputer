#ifndef LO21_EQUAL_COMPARISON_H
#define LO21_EQUALCOMPARISON_H

//|\=|!\=|>|<|>\=|<\=

#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/operator.h"

using namespace std;

/**
 * Definition of an equal comparison operator literal.
 */
class OperatorEqualComparisonLiteralDefinition : public LiteralDefinitionInterface {
public:
    const string getPattern() const override {
        return ">\\=|<\\=";
    }

    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new OperatorLiteral(value));
    }
};

#endif //LO21_EQUAL_COMPARISON_H
