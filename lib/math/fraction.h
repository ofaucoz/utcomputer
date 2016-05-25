#ifndef LO21_MATH_FRACTION_H
#define LO21_MATH_FRACTION_H


class Fraction {
private:
    double numerator;
    double denominator;

public:
    Fraction(double numerator, double denominator) : numerator(numerator), denominator(denominator) { }

    double getNumerator() const {
        return numerator;
    }

    double getDenominator() const {
        return denominator;
    }
};


#endif //LO21_MATH_FRACTION_H
