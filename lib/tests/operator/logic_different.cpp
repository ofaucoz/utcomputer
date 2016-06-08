#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../operator/logic_different.h"

TEST(LogicDifferentOperatorTest, DifferentComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 8, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicDifferentOperator logicDifferentOperator;
    logicDifferentOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicDifferentOperatorTest, EqualsComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicDifferentOperator logicDifferentOperator;
    logicDifferentOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}
