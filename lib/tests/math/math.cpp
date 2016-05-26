#include <gtest/gtest.h>
#include "../../math/math.h"

TEST(MathTest, AddFractions) {
    // Simple case
    Fraction result = Math::add(Fraction(3, 4), Fraction(2, 5));

    EXPECT_EQ(23, result.getNumerator());
    EXPECT_EQ(20, result.getDenominator());

    // Should be simplified
    result = Math::add(Fraction(3, 4), Fraction(1, 6));

    EXPECT_EQ(11, result.getNumerator());
    EXPECT_EQ(12, result.getDenominator());

    // Should be simplified
    result = Math::add(Fraction(2, 4), Fraction(2, 4));

    EXPECT_EQ(1, result.getNumerator());
    EXPECT_EQ(1, result.getDenominator());
}
