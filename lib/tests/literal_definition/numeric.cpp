#include <gtest/gtest.h>
#include "../../literal_definition/numeric.h"

TEST(NumericLiteralDefinitionTest, Construct) {
    NumericLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(NumericLiteralDefinitionTest, CreateInstance) {
    NumericLiteralDefinition definition;

    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(definition.createInstance("3")) != nullptr);

    NumericLiteral* intLiteral = dynamic_cast<NumericLiteral*>(definition.createInstance("36"));
    ASSERT_EQ(36, intLiteral->getRealNumerator());
    ASSERT_EQ(1, intLiteral->getRealDenominator());
    ASSERT_EQ(0, intLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, intLiteral->getImaginaryDenominator());

    NumericLiteral* rationalLiteral = dynamic_cast<NumericLiteral*>(definition.createInstance("36/-4"));
    ASSERT_EQ(36, rationalLiteral->getRealNumerator());
    ASSERT_EQ(-4, rationalLiteral->getRealDenominator());
    ASSERT_EQ(0, rationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, rationalLiteral->getImaginaryDenominator());

    NumericLiteral* complexIntLiteral = dynamic_cast<NumericLiteral*>(definition.createInstance("36$-4"));
    ASSERT_EQ(36, complexIntLiteral->getRealNumerator());
    ASSERT_EQ(1, complexIntLiteral->getRealDenominator());
    ASSERT_EQ(-4, complexIntLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, complexIntLiteral->getImaginaryDenominator());

    NumericLiteral* complexRationalLiteral = dynamic_cast<NumericLiteral*>(definition.createInstance("36/9$-55/7"));
    ASSERT_EQ(36, complexRationalLiteral->getRealNumerator());
    ASSERT_EQ(9, complexRationalLiteral->getRealDenominator());
    ASSERT_EQ(-55, complexRationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(7, complexRationalLiteral->getImaginaryDenominator());

    NumericLiteral* imaginaryRationalLiteral = dynamic_cast<NumericLiteral*>(definition.createInstance("0$-4/5"));
    ASSERT_EQ(0, imaginaryRationalLiteral->getRealNumerator());
    ASSERT_EQ(1, imaginaryRationalLiteral->getRealDenominator());
    ASSERT_EQ(-4, imaginaryRationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(5, imaginaryRationalLiteral->getImaginaryDenominator());
}
