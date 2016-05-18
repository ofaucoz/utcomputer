#ifndef LO21_LITERAL_COMPLEX_H
#define LO21_LITERAL_COMPLEX_H


#include "interface.h"

using namespace std;

/*
 * A numeric literal storing all possible types of numeric values.
 * For instance :
 *      1.4$3/4
 */
struct NumericLiteral : public LiteralInterface {
private:
    double realNumerator;
    double realDenominator;
    double imaginaryNumerator;
    double imaginaryDenominator;

public:
    NumericLiteral(double realNumerator, double realDenominator = 1, double imaginaryNumerator = 0, double imaginaryDenominator = 1)
            : realNumerator(realNumerator), realDenominator(realDenominator), imaginaryNumerator(imaginaryNumerator),
              imaginaryDenominator(imaginaryDenominator) { }

    double getRealNumerator() const {
        return realNumerator;
    }

    double getRealDenominator() const {
        return realDenominator;
    }

    double getImaginaryNumerator() const {
        return imaginaryNumerator;
    }

    double getImaginaryDenominator() const {
        return imaginaryDenominator;
    }

    string toString() const {
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
};


#endif // LO21_LITERAL_COMPLEX_H
