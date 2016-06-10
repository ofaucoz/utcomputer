#include <gtest/gtest.h>
#include "../../operator/numeric_complex_imaginary.h"

TEST(NumericComplexRealImaginaryTest, ComplexLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    NumericComplexImaginaryOperator numericComplexImaginary;
    numericComplexImaginary.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("5/6", stack.top()->toString());
}

TEST(NumericComplexImaginaryTest, FailInt) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4)));

    EXPECT_EQ(1, stack.size());

    NumericComplexImaginaryOperator numericComplexImaginary;
    EXPECT_THROW(numericComplexImaginary.apply(stack), InvalidOperandException);

    EXPECT_EQ(1, stack.size());
}
