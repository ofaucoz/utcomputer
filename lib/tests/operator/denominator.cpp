#include <gtest/gtest.h>
#include "../../operator/denominator.h"
#include "../../literal/expression.h"

TEST(DenominatorOperatorTest, IntNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4)));

    EXPECT_EQ(1, stack.size());

    DenominatorOperator denominatorOperator;
    denominatorOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
}

TEST(DenominatorOperatorTest, FailComplex) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    DenominatorOperator denominatorOperator;
    EXPECT_THROW(denominatorOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}

TEST(DenominatorOperatorTest, FailNonNumeric) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new ExpressionLiteral("FOO")));

    EXPECT_EQ(1, stack.size());

    DenominatorOperator denominatorOperator;
    EXPECT_THROW(denominatorOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
