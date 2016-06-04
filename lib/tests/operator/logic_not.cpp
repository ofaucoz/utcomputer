#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../exception/invalid_syntax.h"
#include "../../exception/invalid_operand.h"
#include "../../operator/logic_not.h"

TEST(LogicNotOperatNotTest, 1to0) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));

    EXPECT_EQ(1, stack.size());

    LogicNotOperator logicNotOperator;
    logicNotOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}

TEST(LogicNotOperatNotTest, 0to1) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(0)));

    EXPECT_EQ(1, stack.size());

    LogicNotOperator logicNotOperator;
    logicNotOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

