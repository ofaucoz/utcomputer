#include <gtest/gtest.h>
#include "../../operator/multiplication.h"

TEST(MultiplicationOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    MultiplicationOperator multiplicationOperator;
    multiplicationOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("12", stack.top()->toString());
}

TEST(MultiplicationOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));
    stack.push(LiteralPointer(new NumericLiteral(7, 8, 9, 10)));

    EXPECT_EQ(2, stack.size());

    MultiplicationOperator multiplicationOperator;
    multiplicationOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("21/32$3/4", stack.top()->toString());
}

TEST(MultiplicationOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    MultiplicationOperator multiplicationOperator;
    EXPECT_THROW(multiplicationOperator.apply(stack), InvalidSyntaxException);
}

TEST(MultiplicationOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    MultiplicationOperator multiplicationOperator;
    EXPECT_THROW(multiplicationOperator.apply(stack), InvalidOperandException);
}

TEST(MultiplicationOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    MultiplicationOperator multiplicationOperator;
    EXPECT_THROW(multiplicationOperator.apply(stack), InvalidOperandException);
}

