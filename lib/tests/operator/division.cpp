#include <gtest/gtest.h>
#include "../../operator/division.h"

TEST(DivisionOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8)));
    stack.push(LiteralPointer(new NumericLiteral(2)));

    EXPECT_EQ(2, stack.size());

    DivisionOperator divisionOperator;
    divisionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
}

TEST(DivisionOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));
    stack.push(LiteralPointer(new NumericLiteral(7, 8, 9, 10)));

    EXPECT_EQ(2, stack.size());

    DivisionOperator divisionOperator;
    divisionOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("6/7$25/27", stack.top()->toString());
}

TEST(DivisionOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    DivisionOperator divisionOperator;
    EXPECT_THROW(divisionOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(1, stack.size());
}

TEST(DivisionOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    DivisionOperator divisionOperator;
    EXPECT_THROW(divisionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(2, stack.size());
}

TEST(DivisionOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    DivisionOperator divisionOperator;
    EXPECT_THROW(divisionOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(2, stack.size());
}
