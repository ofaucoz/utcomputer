#include <gtest/gtest.h>
#include "../../literal/numeric.h"
#include "../../exception/invalid_syntax.h"
#include "../../exception/invalid_operand.h"
#include "../../operator/logic_equals.h"

TEST(LogicEqualsOperatorTest, EqualsComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));

    EXPECT_EQ(2, stack.size());

    LogicEqualsOperator logicEqualsOperator;
    logicEqualsOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());
}

TEST(LogicEqualsOperatorTest, DifferentComplexArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8,5,4,3)));
    stack.push(LiteralPointer(new NumericLiteral(5,8,4,3)));

    EXPECT_EQ(2, stack.size());

    LogicEqualsOperator logicEqualsOperator;
    logicEqualsOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());
}