#include <gtest/gtest.h>
#include "../../operator/numeric_complex_real.h"
#include "../../literal/numeric.h"
#include "../../exception/invalid_operand.h"

TEST(NumericComplexRealTest, ComplexLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    NumericComplexReal numericComplexReal;
    numericComplexReal.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("3/4", stack.top()->toString());
}

TEST(NumericComplexRealTest, FailInt) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4)));

    EXPECT_EQ(1, stack.size());

    NumericComplexReal numericComplexReal;
    EXPECT_THROW(numericComplexReal.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
