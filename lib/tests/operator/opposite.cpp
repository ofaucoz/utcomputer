#include <gtest/gtest.h>
#include "../../operator/opposite.h"
#include "../../literal/expression.h"

TEST(OppositeOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));

    EXPECT_EQ(1, stack.size());

    OppositeOperator oppositeOperator;
    oppositeOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("-4", stack.top()->toString());
}

TEST(OppositeOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    OppositeOperator oppositeOperator;
    oppositeOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("-3/4$5/6", stack.top()->toString());
}

TEST(OppositeOperatorTest, FailNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(1, stack.size());

    OppositeOperator oppositeOperator;
    EXPECT_THROW(oppositeOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
