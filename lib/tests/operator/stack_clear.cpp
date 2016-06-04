#include <gtest/gtest.h>
#include "../../operator/stack_clear.h"
#include "../../literal/numeric.h"

TEST(StackClearOperator, ClearLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    StackClearOperator stackClearOperator;
    stackClearOperator.apply(stack);

    EXPECT_EQ(0, stack.size());

}


TEST(StackClearOperator, FailEmptyStackClear) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    StackClearOperator stackClearOperator;
    stackClearOperator.apply(stack);

    EXPECT_THROW(stackClearOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(0, stack.size());
}

