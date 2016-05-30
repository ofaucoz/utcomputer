#include <gtest/gtest.h>
#include "../../operator/addition.h"

TEST(AdditionOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    AdditionOperator additionOperator;
    additionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("7", stack.top()->toString());
}

TEST(AdditionOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 1, 6)));
    stack.push(LiteralPointer(new NumericLiteral(1, 6, 3, 4)));

    EXPECT_EQ(2, stack.size());

    AdditionOperator additionOperator;
    additionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("11/12$11/12", stack.top()->toString());
}

TEST(AdditionOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    AdditionOperator additionOperator;
    EXPECT_THROW(additionOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(0, stack.size());
}

TEST(AdditionOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    AdditionOperator additionOperator;
    EXPECT_THROW(additionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}

TEST(AdditionOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    AdditionOperator additionOperator;
    EXPECT_THROW(additionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
