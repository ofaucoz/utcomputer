#ifndef LO21_MATH_MATH_H
#define LO21_MATH_MATH_H


#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;

/*
 * Maths useful algorithms
 */
class Math {
public:

    /*
     * Add two fractions
     */
    static Fraction add(Fraction f1, Fraction f2) {
        return simplify(
            Fraction(
                f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator(),
                f1.getDenominator() * f2.getDenominator()
            )
        );
    }

    /*
     * Substract two fractions
     */
    static Fraction substract(Fraction f1, Fraction f2) {
        return simplify(
            Fraction(
                (f1.getNumerator() * f2.getDenominator()) - (f2.getNumerator() * f1.getDenominator()),
                f1.getDenominator() * f2.getDenominator()
            )
        );
    }

    /*
     * Simplify a given fraction using the GCD
     */
    static Fraction simplify(Fraction f) {
        // Simple case
        if (f.getNumerator() == f.getDenominator()) {
            return Fraction(1, 1);
        }

        // We don't simplify fractions containing non-int values
        if (!isInt(f.getNumerator()) || !isInt(f.getDenominator())) {
            return f;
        }

        int num = (int) f.getNumerator();
        int dem = (int) f.getDenominator();

        double fGcd = gcd((num >= 0 ? num : -num), (dem >= 0 ? dem : -dem));

        return Fraction(f.getNumerator() / fGcd, f.getDenominator() / fGcd);
    }

    /*
     * Is the given double value actually an int
     */
    static bool isInt(double value) {
        double intpart;
        return modf(value, &intpart) == 0.0;
    }

    /*
     * Compute the greatest common divisor between two given number
     * Extracted from https://en.wikipedia.org/wiki/Binary_GCD_algorithm
     */
    static int gcd(int u, int v)
    {
        // Simple cases
        if (u == v) {
            return u;
        } else if (u == 0) {
            return v;
        } else if (v == 0) {
            return u;
        }

        // Look for factors of 2
        if (~u & 1) {
            // u is even

            if (v & 1) {
                // v is odd
                return gcd(u >> 1, v);
            } else {
                // Both u and v are even
                return gcd(u >> 1, v >> 1) << 1;
            }
        }

        if (~v & 1) {
            // u is odd, v is even
            return gcd(u, v >> 1);
        }

        // Reduce larger argument
        if (u > v) {
            return gcd((u - v) >> 1, v);
        }

        return gcd((v - u) >> 1, u);
    }

};

#endif // LO21_MATH_MATH_H
