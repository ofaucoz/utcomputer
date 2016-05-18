#include "numeric.h"

string NumericLiteral::toString() const {
    string value = "0";

    if (realNumerator != 0) {
        value = to_string(realNumerator);

        if (realDenominator != 1) {
            value += "/" + to_string(realDenominator);
        }
    }

    if (imaginaryNumerator != 0) {
        value += "$" + to_string(imaginaryNumerator);

        if (imaginaryDenominator != 1) {
            value += "/" + to_string(imaginaryDenominator);
        }
    }

    return value;
};