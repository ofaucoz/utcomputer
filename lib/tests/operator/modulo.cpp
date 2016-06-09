#include <gtest/gtest.h>
#include "../../literal/expression.h"
#include "../../operator/modulo.h"

TEST(ModuloOperatorTest, IntNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(9)));
    stack.push(LiteralPointer(new NumericLiteral(2)));

    EXPECT_EQ(2, stack.size());

    ModuloOperator moduloOperator;
    moduloOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(ModuloOperatorTest, ComplexNumerics) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));
    stack.push(LiteralPointer(new NumericLiteral(7, 8, 9, 10)));

    EXPECT_EQ(2, stack.size());

    ModuloOperator moduloOperator;
    EXPECT_THROW(moduloOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}

TEST(ModuloOperatorTest, FailNotEnoughOperands) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    ModuloOperator moduloOperator;
    EXPECT_THROW(moduloOperator.apply(stack), InvalidSyntaxException);
}

TEST(ModuloOperatorTest, FailFirstNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    ModuloOperator moduloOperator;
    EXPECT_THROW(moduloOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}

TEST(ModuloOperatorTest, FailSecondNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(2, stack.size());

    ModuloOperator moduloOperator;
    EXPECT_THROW(moduloOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
