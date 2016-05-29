#include <gtest/gtest.h>
#include "../../operator/euclidian_division.h"

TEST(EuclidianDivisionOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(9)));
    stack.push(LiteralPointer(new NumericLiteral(2)));

    EXPECT_EQ(2, stack.size());

    EuclidianDivisionOperator euclidianDivisionOperator;
    euclidianDivisionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
}

TEST(EuclidianDivisionOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));
    stack.push(LiteralPointer(new NumericLiteral(7, 8, 9, 10)));

    EXPECT_EQ(2, stack.size());

    EuclidianDivisionOperator euclidianDivisionOperator;
    EXPECT_THROW(euclidianDivisionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(2, stack.size());
}

TEST(EuclidianDivisionOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    EuclidianDivisionOperator euclidianDivisionOperator;
    EXPECT_THROW(euclidianDivisionOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(1, stack.size());
}

TEST(EuclidianDivisionOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    EuclidianDivisionOperator euclidianDivisionOperator;
    EXPECT_THROW(euclidianDivisionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(2, stack.size());
}

TEST(EuclidianDivisionOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    EuclidianDivisionOperator euclidianDivisionOperator;
    EXPECT_THROW(euclidianDivisionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(2, stack.size());
}
