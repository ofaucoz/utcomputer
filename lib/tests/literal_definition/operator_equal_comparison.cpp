#include <gtest/gtest.h>
#include "../../literal_definition/operator_equal_comparison.h"

TEST(OperatorEqualComparisonLiteralDefinitionTest, Construct) {
    OperatorEqualComparisonLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(OperatorEqualComparisonLiteralDefinitionTest, CreateInstanceNative) {
    OperatorEqualComparisonLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance(">=")) != nullptr);

    LiteralPointer literal = definition.createInstance(">=");
    EXPECT_EQ(">=", literal->toString());
}


