#ifndef LO21_LITERAL_NUMERIC_H
#define LO21_LITERAL_NUMERIC_H


#include "interface.h"
#include "../math/math.h"
#include "../math/fraction.h"

using namespace std;

/**
 * A numeric literal storing all possible types of numeric values.
 * For instance :
 *      1.4$3/4
 *
 * Each numeric literal is splitted in 4 parts:
 *      - a real numerator
 *      - a real denomiator
 *      - a imaginary numerator
 *      - a imaginary denomiator
 *
 * Having a single numeric literal is useful for calculation: instead
 * of having to create each operator for integers, doubles, rationnals,
 * complexs, ..., we only create them for the NumericLiteral and then this
 * literal is displayed according to its real type.
 */
struct NumericLiteral: public LiteralInterface {
private:
    double realNumerator;
    double realDenominator;
    double imaginaryNumerator;
    double imaginaryDenominator;

    /**
     * Create the string representation of a double according to its
     * real type (if it's an integer, an integer will be displayed).
     */
    const string formatDouble(double value) const;

public:
    /**
     * Create a NumericLiteral from its basic components.
     *
     * @param realNumerator The real numerator.
     * @param realDenominator The real denominator (if there is one).
     * @param imaginaryNumerator The imaginary numerator (if there is one).
     * @param imaginaryDenominator The imaginary denominator (if there is one).
     */
    NumericLiteral(double realNumerator,
                   double realDenominator = 1,
                   double imaginaryNumerator = 0,
                   double imaginaryDenominator = 1) :
        realNumerator(realNumerator),
        realDenominator(realDenominator),
        imaginaryNumerator(imaginaryNumerator),
        imaginaryDenominator(imaginaryDenominator) { }

    /**
     * Create a NumericLiteral from two fractions: one for the real part
     * and one for the imaginary one.
     *
     * @param real The real fraction.
     * @param imaginary The imaginary fraction.
     */
    NumericLiteral(Fraction real, Fraction imaginary) {
        realNumerator = real.getNumerator();
        realDenominator = real.getDenominator();
        imaginaryNumerator = imaginary.getNumerator();
        imaginaryDenominator = imaginary.getDenominator();
    }

    /**
     * @return The real numerator.
     */
    double getRealNumerator() const {
        return realNumerator;
    }

    /**
     * @return The real denominator.
     */
    double getRealDenominator() const {
        return realDenominator;
    }

    /**
     * @return The imaginary numerator.
     */
    double getImaginaryNumerator() const {
        return imaginaryNumerator;
    }

    /**
     * @return The imaginary denominator.
     */
    double getImaginaryDenominator() const {
        return imaginaryDenominator;
    }

    /**
     * @return The real fraction.
     */
    Fraction getRealFraction() const {
        return Fraction(realNumerator, realDenominator);
    }

    /**
     * @return The imaginary fraction.
     */
    Fraction getImaginaryFraction() const {
        return Fraction(imaginaryNumerator, imaginaryDenominator);
    }

    /**
     * The string representation of a number vary a lot depending on its type:
     *      - integer and double are simply displayed
     *      - rationnal are displayed with a slash ("/")
     *      - complex are displayed with a dollar ("$")
     *
     * This method take care of this.
     *
     * @return The string representation of this literal.
     */
    const string toString() const override;
};

typedef shared_ptr<NumericLiteral> NumericLiteralPointer;


#endif // LO21_LITERAL_NUMERIC_H
