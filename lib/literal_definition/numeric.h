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
 * Definition of a numeric literal.
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
    queue<string> parse(string value) const {
        queue<string> parsed;
        string input = "";

        for (int i = 0; i < value.size(); i++) {
            if (value[i] != '$' && value[i] != '/') {
                input += value[i];

                if (value[i + 1] == '\0') {
                    parsed.push(input);
                    input = "";
                }
            } else if (value[i] == '/') {
                parsed.push(input);
                input = "";
                parsed.push("/");
            } else {  // value[i] == '$'
                parsed.push(input);
                parsed.push("$");
                input = "";
            }
        }

        return parsed;
    }

public:
    string getPattern() const {
        return "([0-9]+/?[0-9]?+\\$?[0-9]?+/?[0-9]?+)";
    }

    LiteralInterface *createInstance(string value) const {
        queue<string> parsedString = parse(value);

        bool isRational = false;
        bool isComplex = false;

        double realNumerator = 0;
        double realDenominator = 1;
        double imagNumerator = 0;
        double imagDenominator = 1;

        unsigned long size = parsedString.size();

        for (int i = 0; i < size; i++) {
            if (parsedString.front() == "/") {
                // Next number will be a denominator
                isRational = true;
                parsedString.pop();
            } else if (parsedString.front() == "$") {
                // Next numbers will be imaginary
                isComplex = true;
                parsedString.pop();
            } else if (! isRational && ! isComplex) {
                // Not a denominator and not complex ==> real numerator
                realNumerator = stod(parsedString.front());
                parsedString.pop();
            } else if (! isRational) {
                imagNumerator = stod(parsedString.front());
                parsedString.pop();
            } else if (! isComplex) {
                realDenominator = stod(parsedString.front());
                parsedString.pop();
                isRational = false;
            } else {
                // Denominator and imaginary ==> imaginary denominator
                imagDenominator = stod(parsedString.front());
                parsedString.pop();
                isRational = false;
            }
        }

        return new NumericLiteral(realNumerator, realDenominator, imagNumerator, imagDenominator);
    }
};


#endif //LO21_LITERAL_DEFINITION_NUMERIC_H
