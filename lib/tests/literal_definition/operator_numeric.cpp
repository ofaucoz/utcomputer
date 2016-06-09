#include <gtest/gtest.h>
#include "../../literal_definition/operator_numeric.h"

TEST(OperatorLiteralDefinitionTest, Construct) {
    OperatorNumericLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(OperatorLiteralDefinitionTest, CreateInstanceNative) {
    OperatorNumericLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance("+")) != nullptr);

    LiteralPointer literal = definition.createInstance("+");
    EXPECT_EQ("+", literal->toString());
}

TEST(OperatorLiteralDefinitionTest, CreateInstance) {
    OperatorNumericLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance("FOO")) != nullptr);

    LiteralPointer literal = definition.createInstance("FOO");
    EXPECT_EQ("FOO", literal->toString());
}
