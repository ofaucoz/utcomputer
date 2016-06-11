#include <gtest/gtest.h>
#include "../../operator/sto.h"

TEST(StoOperator, NumAndAtom) {
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
}

TEST(StoOperator, ExpAndAtom) {
    LiteralsStack stack;
    VariableMap variableMap;
    stack.push(LiteralPointer(new ExpressionLiteral("'3+5*6'")));
    stack.push(LiteralPointer(new ExpressionLiteral("'MULTIPLI'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap);
    stoOperator.apply(stack);

    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(1, variableMap.size());
    EXPECT_EQ("'3+5*6'", variableMap.get("MULTIPLI")->toString());
}

TEST(StoOperator, FailNotExpressionFirstPopped) {
    LiteralsStack stack;
    VariableMap variableMap;
    stack.push(LiteralPointer(new NumericLiteral(4, 5, 4, 5)));
    stack.push(LiteralPointer(new NumericLiteral(5)));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap);

    EXPECT_THROW(stoOperator.apply(stack), InvalidOperandException);
}

TEST(StoOperator, FailNotAtomFirstPopped) {
    LiteralsStack stack;
    VariableMap variableMap;
    stack.push(LiteralPointer(new ExpressionLiteral("'3+5*6'")));
    stack.push(LiteralPointer(new NumericLiteral(5)));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap);

    EXPECT_THROW(stoOperator.apply(stack), InvalidOperandException);
}
