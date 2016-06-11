#include <gtest/gtest.h>
#include "../../operator/numeric_complex_build.h"

TEST(NumericComplexBuildOperatorTest, IntArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8)));
    stack.push(LiteralPointer(new NumericLiteral(2)));

    EXPECT_EQ(2, stack.size());

    NumericComplexBuildOperator numericComplexBuildOperator;
    numericComplexBuildOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("8$2", stack.top()->toString());
}

TEST(NumericComplexBuildOperatorTest, FractionArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 2)));
    stack.push(LiteralPointer(new NumericLiteral(2, 4)));

    EXPECT_EQ(2, stack.size());

    NumericComplexBuildOperator numericComplexBuildOperator;
    numericComplexBuildOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("8/2$2/4", stack.top()->toString());
}

TEST(NumericComplexBuildOperatorTest, WrongArguments) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(8, 1, 5, 4)));
    stack.push(LiteralPointer(new NumericLiteral(2)));

    EXPECT_EQ(2, stack.size());

    NumericComplexBuildOperator numericComplexBuildOperator;
    EXPECT_THROW(numericComplexBuildOperator.apply(stack), InvalidSyntaxException);

}
