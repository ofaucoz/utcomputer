#include <gtest/gtest.h>
#include "../../literal/atom.h"
#include "../../literal/complex.h"
#include "../../literal/expression.h"
#include "../../literal/int.h"
#include "../../literal/program.h"
#include "../../literal/rationnal.h"
#include "../../literal/real.h"

TEST(AtomLiteralTest, ConstructAndToString) {
    AtomLiteral atomLiteral("FOO");

    ASSERT_EQ("FOO", atomLiteral.getValue());
    ASSERT_EQ("FOO", atomLiteral.toString());
}

TEST(IntLiteralTest, ConstructAndToString) {
    IntLiteral intLiteral(4);

    ASSERT_EQ(4, intLiteral.getValue());
    ASSERT_EQ("4", intLiteral.toString());
}

TEST(RationnalLiteralTest, ConstructAndToString) {
    RationnalLiteral rationnalLiteral(-3, 4);

    ASSERT_EQ(-3, rationnalLiteral.getNumerator());
    ASSERT_EQ(4, rationnalLiteral.getDenominator());
    ASSERT_EQ("-3/4", rationnalLiteral.toString());
}

TEST(RealLiteralTest, ConstructAndToString) {
    RealLiteral realLiteral(-3.14);

    ASSERT_EQ(realLiteral.getValue(), -3.14);
    ASSERT_EQ(realLiteral.toString(), "-3.140000");
}

TEST(ComplexLiteral, ConstructAndToString) {
    RationnalLiteral rationnalLiteral(-3, 4);
    RealLiteral realLiteral(3.14);
    ComplexLiteral complexLiteral(realLiteral, rationnalLiteral);

    ASSERT_EQ(realLiteral.toString(), complexLiteral.getReal().toString());
    ASSERT_EQ(rationnalLiteral.toString(), complexLiteral.getImaginary().toString());
    ASSERT_EQ("3.140000$-3/4", complexLiteral.toString());
}

TEST(ExpressionLiteralTest, ConstructAndToString) {
    ExpressionLiteral expressionLiteral("'FOO 3 +'");

    ASSERT_EQ(expressionLiteral.getValue(), "'FOO 3 +'");
    ASSERT_EQ(expressionLiteral.toString(), "'FOO 3 +'");
}

TEST(ProgramLiteralTest, ConstructAndToString) {
    ProgramLiteral programLiteral("[FOO 3 +]");

    ASSERT_EQ(programLiteral.getValue(), "[FOO 3 +]");
    ASSERT_EQ(programLiteral.toString(), "[FOO 3 +]");
}
