#ifndef LO21_MATH_MATH_H
#define LO21_MATH_MATH_H


#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;

/**
 * Mathematic useful algorithms based on franctions.
 */
class Math {
public:

    /**
     * Add two fractions.
     *
     * @param f1 The first fraction.
     * @param f2 The second fraction.
     * @return The fraction resulting of the addition of f1 and f2.
     */
    static Fraction add(Fraction f1, Fraction f2);

    /**
     * Substract two fractions.
     *
     * @param f1 The first fraction.
     * @param f2 The second fraction.
     * @return The fraction resulting of the substraction of f2 from f1.
     */
    static Fraction substract(Fraction f1, Fraction f2);

    /**
     * Simplify a given fraction using the GCD.
     *
     * @param f The fraction to simplify.
     * @return The simplified fraction.
     */
    static Fraction simplify(Fraction f);

    /**
     * Check if the given double is actually an integer.
     *
     * @param value The value to check.
     * @return Whether it is an integer or not.
     */
    static bool isInt(double value);

    /*
     * Compute the greatest common divisor between two given number.
     *
     * @see https://en.wikipedia.org/wiki/Binary_GCD_algorithm
     *
     * @param u The first integer.
     * @param v The second integer.
     * @return The Greatest Common Divisor between u and v.
     */
    static int gcd(int u, int v);

};

#endif // LO21_MATH_MATH_H
