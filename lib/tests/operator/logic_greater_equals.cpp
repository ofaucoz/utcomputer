#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../operator/logic_greater_equals.h"

TEST(LogicGreaterEqualsOperatorTest, GreaterComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 5, 3, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterEqualsOperator logicGreaterEqualsOperator;
    logicGreaterEqualsOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicGreaterEqualsOperatorTest, LesserComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(2, 5, 3, 3)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterEqualsOperator logicGreaterEqualsOperator;
    logicGreaterEqualsOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}

TEST(LogicGreaterEqualsOperatorTest, EqualsComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(4, 3, 5, 5)));
    stack.push(LiteralPointer(new NumericLiteral(5, 5, 4, 3)));

    EXPECT_EQ(2, stack.size());

    LogicGreaterEqualsOperator logicGreaterEqualsOperator;
    logicGreaterEqualsOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}
