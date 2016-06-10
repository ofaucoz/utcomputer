#include <gtest/gtest.h>
#include "../../operator/numerator.h"
#include "../../literal/expression.h"

TEST(NumeratorOperatorTest, IntNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4)));

    EXPECT_EQ(1, stack.size());

    NumeratorOperator numeratorOperator;
    numeratorOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("3", stack.top()->toString());
}

TEST(NumeratorOperatorTest, FailComplex) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    NumeratorOperator numeratorOperator;
    EXPECT_THROW(numeratorOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(1, stack.size());
}

TEST(NumeratorOperatorTest, FailNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(1, stack.size());

    NumeratorOperator numeratorOperator;
    EXPECT_THROW(numeratorOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(1, stack.size());
}
