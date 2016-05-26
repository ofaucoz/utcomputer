#ifndef LO21_LITERAL_COMPLEX_H
#define LO21_LITERAL_COMPLEX_H


#include "interface.h"
#include "../math/math.h"
#include "../math/fraction.h"

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

    const string formatDouble(double value) const;

public:
    NumericLiteral(double realNumerator,
                   double realDenominator = 1,
                   double imaginaryNumerator = 0,
                   double imaginaryDenominator = 1) :
        realNumerator(realNumerator),
        realDenominator(realDenominator),
        imaginaryNumerator(imaginaryNumerator),
        imaginaryDenominator(imaginaryDenominator) { }

    NumericLiteral(Fraction real, Fraction imaginary) {
        realNumerator = real.getNumerator();
        realDenominator = real.getDenominator();
        imaginaryNumerator = imaginary.getNumerator();
        imaginaryDenominator = imaginary.getDenominator();
    }

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

    Fraction getRealFraction() const {
        return Fraction(realNumerator, realDenominator);
    }

    Fraction getImaginaryFraction() const {
        return Fraction(imaginaryNumerator, imaginaryDenominator);
    }

    const string toString() const override;
};

/*
 * Numeric literal pointer
 */
typedef shared_ptr<NumericLiteral> NumericLiteralPointer;


#endif // LO21_LITERAL_COMPLEX_H
