#include "math.h"

Fraction Math::add(Fraction f1, Fraction f2) {
    return simplify(
        Fraction(
            f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator(),
            f1.getDenominator() * f2.getDenominator()
        )
    );
}

Fraction Math::substract(Fraction f1, Fraction f2) {
    return simplify(
        Fraction(
            (f1.getNumerator() * f2.getDenominator()) - (f2.getNumerator() * f1.getDenominator()),
            f1.getDenominator() * f2.getDenominator()
        )
    );
}

Fraction Math::simplify(Fraction f) {
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

double Math::module(Fraction real, Fraction imaginary) {
    double realNum = real.getNumerator();
    double realDen = real.getDenominator();
    double imagNum = imaginary.getNumerator();
    double imagDen = imaginary.getDenominator();

    return sqrt((pow(realNum, 2) / pow(realDen, 2)) + (pow(imagNum, 2) / pow(imagDen, 2)));
}

bool Math::isInt(double value) {
    double intpart;
    return modf(value, &intpart) == 0.0;
}

int Math::gcd(int u, int v) {
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
