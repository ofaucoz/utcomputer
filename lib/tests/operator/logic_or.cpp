#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../operator/logic_or.h"

TEST(LogicOrOperatorTest, IntLiteralOrIntLiteral) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 8, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicOrOperator logicOrOperator;
    logicOrOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicOrOperatorTest, IntLiteralOr0) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));
    stack.push(LiteralPointer(new NumericLiteral(0)));

    EXPECT_EQ(2, stack.size());

    LogicOrOperator logicOrOperator;
    logicOrOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicOrOperatorTest, 0OrIntLiteral) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(0)));
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 4, 3)));


    EXPECT_EQ(2, stack.size());

    LogicOrOperator logicOrOperator;
    logicOrOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicOrOperatorTest, 0OrInt0) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(0)));
    stack.push(LiteralPointer(new NumericLiteral(0)));


    EXPECT_EQ(2, stack.size());

    LogicOrOperator logicOrOperator;
    logicOrOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}
