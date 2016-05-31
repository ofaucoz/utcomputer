#ifndef LO21_LITERAL_DEFINITION_NUMERIC_H
#define LO21_LITERAL_DEFINITION_NUMERIC_H


#include <iostream>
#include <regex>
#include <queue>
#include <stdlib.h>
#include "interface.h"
#include "../literal/numeric.h"

using namespace std;

/*
 * Definition of an atom literal.
 */
class NumericLiteralDefinition : public LiteralDefinitionInterface {
private:
    /**
     * Split the given string into a queue of elements to extract
     * each number.
     *
     * For instance, 36/9$55/7 will be transformed into:
     *      36
     *      /
     *      9
     *      $
     *      55
     *      /
     *      7
     *
     * This method is used by the definition to build numeric literals
     * given a string.
     */
    queue<std::string> parse(string value) const;

public:
    const string getPattern() const override {
        return "(-?[0-9]+(\\.[0-9]+)?)(/-?[0-9]+(\\.[0-9]+)?)?(\\$(-?[0-9]+(\\.[0-9]+)?)(/-?[0-9]+(\\.[0-9]+)?)?)?";
    }

    LiteralPointer createInstance(string value) const override;
};


#endif //LO21_LITERAL_DEFINITION_NUMERIC_H
