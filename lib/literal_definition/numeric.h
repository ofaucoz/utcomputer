#ifndef LO21_LITERAL_DEFINITION_NUMERIC_H
#define LO21_LITERAL_DEFINITION_NUMERIC_H


#include <iostream>
#include <regex>
#include <queue>
#include <stdlib.h>
#include "interface.h"
#include "../literal/numeric.h"

using namespace std;

/**
 * Definition of a numeric literal.
 */
class NumericLiteralDefinition: public LiteralDefinitionInterface {
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
     *
     * @param value The string to parse.
     * @return The queue used in the createInstance method to build the literal.
     */
    queue<std::string> parse(string value) const;

public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "(-?[0-9]+(\\.[0-9]+)?)(/-?[0-9]+(\\.[0-9]+)?)?(\\$(-?[0-9]+(\\.[0-9]+)?)(/-?[0-9]+(\\.[0-9]+)?)?)?";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override;

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<NumericLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 8) == "numeric:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        NumericLiteralPointer numericLiteral = dynamic_pointer_cast<NumericLiteral>(literal);
        return "numeric:" + numericLiteral->toString();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(8));
    }
};


#endif //LO21_LITERAL_DEFINITION_NUMERIC_H
