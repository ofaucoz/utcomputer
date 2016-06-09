#include <gtest/gtest.h>
#include "../../literal_definition/operator_strict_comparison.h"

TEST(OperatorStrictComparisonLiteralDefinitionTest, Construct) {
    OperatorStrictComparisonLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(OperatorStrictComparisonLiteralDefinitionTest, CreateInstanceNative) {
    OperatorStrictComparisonLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance(">")) != nullptr);

    LiteralPointer literal = definition.createInstance(">");
    EXPECT_EQ(">", literal->toString());
}


