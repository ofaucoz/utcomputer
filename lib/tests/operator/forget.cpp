#include <gtest/gtest.h>
#include "../../operator/sto.h"
#include "../../operator/forget.h"

TEST(ForgetOperator, NumAndAtomGoodDeletion) {
    LiteralsStack stack;
    VariableMap variableMap;
    stack.push(LiteralPointer(new NumericLiteral(4, 5, 4, 5)));
    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap);
    stoOperator.apply(stack);

    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(1, variableMap.size());
    EXPECT_EQ("4/5$4/5", variableMap.get("AFR")->toString());

    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(1, stack.size());

    ForgetOperator forgetOperator(variableMap);
    forgetOperator.apply(stack);

    EXPECT_EQ(0, variableMap.size());
}

TEST(ForgetOperator, FailNotExpressionForgetAtom) {
    LiteralsStack stack;
    VariableMap variableMap;
    stack.push(LiteralPointer(new NumericLiteral(4, 5, 4, 5)));
    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap);
    stoOperator.apply(stack);

    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    ForgetOperator forgetOperator(variableMap);

    EXPECT_THROW(forgetOperator.apply(stack), InvalidOperandException);
}

