#include <gtest/gtest.h>
#include "../../literal_definition/numeric.h"

TEST(NumericLiteralDefinitionTest, Pattern) {
    NumericLiteralDefinition definition;

    EXPECT_TRUE(regex_match("36", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("-36", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36.4", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("-36.4", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36/4", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("-36/4", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("-36.4/4.2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36$4", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36/3$4/2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("-36/3$4/2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36/3$-4/2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36/-3$4/2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36/-3$4/-2", regex("^(" + definition.getPattern() + ")")));
    EXPECT_TRUE(regex_match("36.4/-3.4$4.4/-2.4", regex("^(" + definition.getPattern() + ")")));
}

TEST(NumericLiteralDefinitionTest, CreateInstance) {
    NumericLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(definition.createInstance("3")) != nullptr);

    NumericLiteralPointer intLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36"));
    EXPECT_EQ(36, intLiteral->getRealNumerator());
    EXPECT_EQ(1, intLiteral->getRealDenominator());
    EXPECT_EQ(0, intLiteral->getImaginaryNumerator());
    EXPECT_EQ(1, intLiteral->getImaginaryDenominator());

    NumericLiteralPointer rationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36/-4"));
    EXPECT_EQ(36, rationalLiteral->getRealNumerator());
    EXPECT_EQ(-4, rationalLiteral->getRealDenominator());
    EXPECT_EQ(0, rationalLiteral->getImaginaryNumerator());
    EXPECT_EQ(1, rationalLiteral->getImaginaryDenominator());

    NumericLiteralPointer complexIntLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36$-4"));
    EXPECT_EQ(36, complexIntLiteral->getRealNumerator());
    EXPECT_EQ(1, complexIntLiteral->getRealDenominator());
    EXPECT_EQ(-4, complexIntLiteral->getImaginaryNumerator());
    EXPECT_EQ(1, complexIntLiteral->getImaginaryDenominator());

    NumericLiteralPointer complexRationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("36/9$-55/7"));
    EXPECT_EQ(36, complexRationalLiteral->getRealNumerator());
    EXPECT_EQ(9, complexRationalLiteral->getRealDenominator());
    EXPECT_EQ(-55, complexRationalLiteral->getImaginaryNumerator());
    EXPECT_EQ(7, complexRationalLiteral->getImaginaryDenominator());

    NumericLiteralPointer imaginaryRationalLiteral = dynamic_pointer_cast<NumericLiteral>(definition.createInstance("0$-4/5"));
    EXPECT_EQ(0, imaginaryRationalLiteral->getRealNumerator());
    EXPECT_EQ(1, imaginaryRationalLiteral->getRealDenominator());
    EXPECT_EQ(-4, imaginaryRationalLiteral->getImaginaryNumerator());
    EXPECT_EQ(5, imaginaryRationalLiteral->getImaginaryDenominator());
}
