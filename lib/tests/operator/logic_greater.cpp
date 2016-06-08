#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../operator/logic_greater.h"

TEST(LogicGreaterOperatorTest, GreaterComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 3, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterOperator logicGreaterOperator;
    logicGreaterOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicGreaterperatorTest, LesserComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(2, 5, 3, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterOperator logicGreaterOperator;
    logicGreaterOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}

TEST(LogicGreaterperatorTest, LesserIntArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(2, 5)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterOperator logicGreaterOperator;
    logicGreaterOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}
