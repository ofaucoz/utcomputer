#include <gtest/gtest.h>
#include "../../literal_definition/numeric.h"

TEST(NumericLiteralDefinitionTest, Construct) {
    NumericLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(NumericLiteralDefinitionTest, CreateInstance) {
    NumericLiteralDefinition definition;

    ASSERT_TRUE(dynamic_pointer_cast<NumericLiteral>(definition.createInstance("3")) != nullptr);

    shared_ptr<NumericLiteral> intLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36"));
    ASSERT_EQ(36, intLiteral->getRealNumerator());
    ASSERT_EQ(1, intLiteral->getRealDenominator());
    ASSERT_EQ(0, intLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, intLiteral->getImaginaryDenominator());

    shared_ptr<NumericLiteral> rationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36/-4"));
    ASSERT_EQ(36, rationalLiteral->getRealNumerator());
    ASSERT_EQ(-4, rationalLiteral->getRealDenominator());
    ASSERT_EQ(0, rationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, rationalLiteral->getImaginaryDenominator());

    shared_ptr<NumericLiteral> complexIntLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36$-4"));
    ASSERT_EQ(36, complexIntLiteral->getRealNumerator());
    ASSERT_EQ(1, complexIntLiteral->getRealDenominator());
    ASSERT_EQ(-4, complexIntLiteral->getImaginaryNumerator());
    ASSERT_EQ(1, complexIntLiteral->getImaginaryDenominator());

    shared_ptr<NumericLiteral> complexRationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36/9$-55/7"));
    ASSERT_EQ(36, complexRationalLiteral->getRealNumerator());
    ASSERT_EQ(9, complexRationalLiteral->getRealDenominator());
    ASSERT_EQ(-55, complexRationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(7, complexRationalLiteral->getImaginaryDenominator());

    shared_ptr<NumericLiteral> imaginaryRationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("0$-4/5"));
    ASSERT_EQ(0, imaginaryRationalLiteral->getRealNumerator());
    ASSERT_EQ(1, imaginaryRationalLiteral->getRealDenominator());
    ASSERT_EQ(-4, imaginaryRationalLiteral->getImaginaryNumerator());
    ASSERT_EQ(5, imaginaryRationalLiteral->getImaginaryDenominator());
}
