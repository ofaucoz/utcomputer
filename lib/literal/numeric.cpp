#include "numeric.h"

const string NumericLiteral::formatDouble(double value) const {
    if (Math::isInt(value)) {
        return to_string((int) value);
    }

    return to_string(value);
};

const string NumericLiteral::toString() const {
    string value = "0";

    if (realNumerator != 0) {
        value = formatDouble(realNumerator);

        if (realDenominator != 1) {
            value += "/" + formatDouble(realDenominator);
        }
    }

    if (imaginaryNumerator != 0) {
        value += "$" + formatDouble(imaginaryNumerator);

        if (imaginaryDenominator != 1) {
            value += "/" + formatDouble(imaginaryDenominator);
        }
    }

    return value;
};
