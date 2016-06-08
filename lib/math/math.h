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
    static Fraction add(Fraction f1, Fraction f2);

    /*
     * Substract two fractions
     */
    static Fraction substract(Fraction f1, Fraction f2);

    /*
     * Simplify a given fraction using the GCD
     */
    static Fraction simplify(Fraction f);

    /*
     * Is the given double value actually an int
     */
    static bool isInt(double value);

    /*
     * Compute the greatest common divisor between two given number
     * Extracted from https://en.wikipedia.org/wiki/Binary_GCD_algorithm
     */
    static int gcd(int u, int v);

};

#endif // LO21_MATH_MATH_H
