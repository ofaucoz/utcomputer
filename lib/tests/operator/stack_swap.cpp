#include <gtest/gtest.h>
#include "../../operator/stack_swap.h"
#include "../../literal/numeric.h"

TEST(StackSwapOperator, Swap) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("3", stack.top()->toString());
    EXPECT_EQ("4", stack.second()->toString());

    StackSwapOperator stackSwapOperator;
    stackSwapOperator.apply(stack);

    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
    EXPECT_EQ("3", stack.second()->toString());
}

TEST(StackSwapOperator, Failure) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    StackSwapOperator stackSwapOperator;
    EXPECT_THROW(stackSwapOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(1, stack.size());
}
