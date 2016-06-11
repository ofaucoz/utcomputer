#include <gtest/gtest.h>
#include "../../literal/atom.h"
#include "../../literal/expression.h"
#include "../../literal/numeric.h"
#include "../../literal/operator.h"
#include "../../literal/program.h"
#include "../../literal/whitespace.h"
#include "../../literal/parenthesis.h"

TEST(AtomLiteralTest, ConstructAndToString) {
    AtomLiteral atomLiteral("FOO");

    EXPECT_EQ("FOO", atomLiteral.getValue());
    EXPECT_EQ("FOO", atomLiteral.toString());
}

TEST(ExpressionLiteralTest, ConstructAndToString) {
    ExpressionLiteral expressionLiteral("'FOO 3 +'");

    EXPECT_EQ(expressionLiteral.getValue(), "'FOO 3 +'");
    EXPECT_EQ(expressionLiteral.toString(), "'FOO 3 +'");
}

TEST(NumericLiteral, ConstructAndToString) {
    NumericLiteral intLiteral(-4);
    EXPECT_EQ("-4", intLiteral.toString());

    NumericLiteral rationalLiteral(-4, 2);
    EXPECT_EQ("-4/2", rationalLiteral.toString());

    NumericLiteral complexIntLiteral(3.14, 1, -3, 1);
    EXPECT_EQ("3.140000$-3", complexIntLiteral.toString());

    NumericLiteral complexRationalLiteral(3.14, 2, -3, 4);
    EXPECT_EQ("3.140000/2$-3/4", complexRationalLiteral.toString());

    NumericLiteral imaginaryLiteral(0, 5, 1, 4);
    EXPECT_EQ("0$1/4", imaginaryLiteral.toString());
}

TEST(OperatorLiteralTest, ConstructAndToString) {
    OperatorLiteral operatorLiteral("FOO");

    EXPECT_EQ("FOO", operatorLiteral.getName());
    EXPECT_EQ("FOO", operatorLiteral.toString());
}

TEST(ProgramLiteralTest, ConstructAndToString) {
    ProgramLiteral programLiteral("[FOO 3 +]");

    EXPECT_EQ(programLiteral.getProgram(), "[FOO 3 +]");
    EXPECT_EQ(programLiteral.toString(), "[FOO 3 +]");
}

TEST(WhitespaceLiteralTest, ConstructAndToString) {
    WhitespaceLiteral whitespaceLiteral;

    EXPECT_EQ(whitespaceLiteral.toString(), " ");
}

TEST(ParenthesisLiteralTest, ConstructAndToString) {
    ParenthesisLiteral parenthesisLiteral("(");

    EXPECT_EQ(parenthesisLiteral.getParenthesis(), "(");
    EXPECT_EQ(parenthesisLiteral.toString(), "(");
}
