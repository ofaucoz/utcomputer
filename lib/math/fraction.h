#ifndef LO21_MATH_FRACTION_H
#define LO21_MATH_FRACTION_H


/**
 * Fractions are useful immutable structure for calculation in operators.
 */
class Fraction {
private:
    double numerator;
    double denominator;

public:
    /**
     * @param numerator The fraction numerator.
     * @param denominator The fraction denominator.
     */
    Fraction(double numerator, double denominator) : numerator(numerator), denominator(denominator) { }

    /**
     * @return The fraction numerator.
     */
    double getNumerator() const {
        return numerator;
    }

    /**
     * @return The fraction denominator.
     */
    double getDenominator() const {
        return denominator;
    }
};


#endif //LO21_MATH_FRACTION_H
