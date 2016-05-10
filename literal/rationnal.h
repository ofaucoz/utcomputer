#ifndef LO21_LITERAL_RATIONNAL_H
#define LO21_LITERAL_RATIONNAL_H


#include "literal_interface.h"

struct RationnalLiteral : public NumericLiteralInterface {
private:
    int numerator;
    int denominator;

public:
    RationnalLiteral(int numerator, int denominator): numerator(numerator), denominator(denominator) {}

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }
};


#endif // LO21_LITERAL_RATIONNAL_H
