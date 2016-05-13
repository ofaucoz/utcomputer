#include <gtest/gtest.h>
#include "../../literal/atom.h"
#include "../../literal/expression.h"
#include "../../literal/numeric.h"
#include "../../literal/operator.h"
#include "../../literal/program.h"

TEST(AtomLiteralTest, ConstructAndToString) {
    AtomLiteral atomLiteral("FOO");

    ASSERT_EQ("FOO", atomLiteral.getValue());
    ASSERT_EQ("FOO", atomLiteral.toString());
}

TEST(ExpressionLiteralTest, ConstructAndToString) {
    ExpressionLiteral expressionLiteral("'FOO 3 +'");

    ASSERT_EQ(expressionLiteral.getValue(), "'FOO 3 +'");
    ASSERT_EQ(expressionLiteral.toString(), "'FOO 3 +'");
}

TEST(NumericLiteral, ConstructAndToString) {
    NumericLiteral numericLiteral(-4);
    ASSERT_EQ("-4.000000", numericLiteral.toString());

    NumericLiteral numericLiteral2(3.14, 1, -3, 4);
    ASSERT_EQ("3.140000$-3.000000/4.000000", numericLiteral2.toString());
}

TEST(OperatorLiteralTest, ConstructAndToString) {
    OperatorLiteral operatorLiteral("FOO");

    ASSERT_EQ("FOO", operatorLiteral.getName());
    ASSERT_EQ("FOO", operatorLiteral.toString());
}

TEST(ProgramLiteralTest, ConstructAndToString) {
    ProgramLiteral programLiteral("[FOO 3 +]");

    ASSERT_EQ(programLiteral.getValue(), "[FOO 3 +]");
    ASSERT_EQ(programLiteral.toString(), "[FOO 3 +]");
}
