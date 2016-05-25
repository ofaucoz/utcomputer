#include <gtest/gtest.h>
#include "../../operator/plus.h"

TEST(PlusOperatorTest, AddIntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    PlusOperator plusOperator;
    plusOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("7", stack.top()->toString());
}

TEST(PlusOperatorTest, AddComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 1, 6)));
    stack.push(LiteralPointer(new NumericLiteral(1, 6, 3, 4)));

    EXPECT_EQ(2, stack.size());

    PlusOperator plusOperator;
    plusOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("11/12$11/12", stack.top()->toString());
}

TEST(PlusOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    PlusOperator plusOperator;
    EXPECT_THROW(plusOperator.apply(stack), InvalidSyntaxException);
}

TEST(PlusOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("ADD")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    PlusOperator plusOperator;
    EXPECT_THROW(plusOperator.apply(stack), InvalidOperandException);
}

TEST(PlusOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("ADD")));

    EXPECT_EQ(2, stack.size());

    PlusOperator plusOperator;
    EXPECT_THROW(plusOperator.apply(stack), InvalidOperandException);
}
