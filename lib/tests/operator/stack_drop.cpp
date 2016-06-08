#include <gtest/gtest.h>
#include "../../operator/stack_drop.h"
#include "../../literal/numeric.h"

TEST(StackDropOperator, DropLiterals) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4)));
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(2, stack.size());

    StackDropOperator stackDropOperator;
    stackDropOperator.apply(stack);

    EXPECT_EQ(1, stack.size());

}


TEST(StackDropOperator, FailEmptyStackDrop) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(3)));

    EXPECT_EQ(1, stack.size());

    StackDropOperator stackDropOperator;
    stackDropOperator.apply(stack);

    EXPECT_THROW(stackDropOperator.apply(stack), InvalidSyntaxException);

    EXPECT_EQ(0, stack.size());
}


