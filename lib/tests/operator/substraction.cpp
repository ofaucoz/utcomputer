#include <gtest/gtest.h>
#include "../../operator/substraction.h"

TEST(SubstractionOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    SubstractionOperator substractionOperator;
    substractionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(SubstractionOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 3, 4)));
    stack.push(LiteralPointer(new NumericLiteral(1, 6, 1, 6)));

    EXPECT_EQ(2, stack.size());

    SubstractionOperator substractionOperator;
    substractionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("7/12$7/12", stack.top()->toString());
}

TEST(SubstractionOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    SubstractionOperator substractionOperator;
    EXPECT_THROW(substractionOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(0, stack.size());
}

TEST(SubstractionOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    SubstractionOperator substractionOperator;
    EXPECT_THROW(substractionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}

TEST(SubstractionOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    SubstractionOperator substractionOperator;
    EXPECT_THROW(substractionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
