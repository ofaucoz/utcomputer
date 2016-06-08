#include <gtest/gtest.h>
#include "../../operator/numeric_complex_imaginary.h"
#include "../../literal/expression.h"
#include "../../literal/numeric.h"
#include "../../exception/invalid_operand.h"

TEST(NumericComplexRealImaginaryTest, ComplexLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4,5,6)));

    EXPECT_EQ(1, stack.size());

    NumericComplexImaginary numericComplexImaginary;
    numericComplexImaginary.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("5/6", stack.top()->toString());
}

TEST(NumericComplexImaginaryTest, FailInt) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4)));

    EXPECT_EQ(1, stack.size());

    NumericComplexImaginary numericComplexImaginary;
    EXPECT_THROW(numericComplexImaginary.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}