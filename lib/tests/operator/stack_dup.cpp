#include <gtest/gtest.h>
#include "../../operator/stack_dup.h"
#include "../../literal/numeric.h"

TEST(StackDupOperator, DupLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4,5,6,7)));

    EXPECT_EQ(1, stack.size());

    StackDupOperator stackDupOperator;
    stackDupOperator.apply(stack);

    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("4/5$6/7",stack.top()->toString());
    stack.pop();
    EXPECT_EQ("4/5$6/7",stack.top()->toString());
}

TEST(StackDupOperator, FailEmptyStackDup) {
    LiteralsStack stack;

    EXPECT_EQ(0, stack.size());

    StackDupOperator stackDupOperator;

    EXPECT_THROW(stackDupOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(0, stack.size());
}
