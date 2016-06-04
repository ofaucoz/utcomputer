#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../exception/invalid_syntax.h"
#include "../../exception/invalid_operand.h"
#include "../../operator/logic_and.h"

TEST(LogicAndOperatorTest, IntLiteralANDIntLiteral) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));
    stack.push(LiteralPointer(new NumericLiteral(5,8,4,3)));

    EXPECT_EQ(2, stack.size());

    LogicAndOperator logicAndOperator;
    logicAndOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicAndOperatorTest, IntLiteralAND0) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));
    stack.push(LiteralPointer(new NumericLiteral(0)));

    EXPECT_EQ(2, stack.size());

    LogicAndOperator logicAndOperator;
    logicAndOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}

TEST(LogicAndOperatorTest, 0ANDIntLiteral) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(0)));
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));


    EXPECT_EQ(2, stack.size());

    LogicAndOperator logicAndOperator;
    logicAndOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}

TEST(LogicAndOperatorTest, 0ANDInt0) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(0)));
    stack.push(LiteralPointer(new NumericLiteral(0)));


    EXPECT_EQ(2, stack.size());

    LogicAndOperator logicAndOperator;
    logicAndOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}