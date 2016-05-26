#include <gtest/gtest.h>
#include "../../literal_definition/operator.h"

TEST(OperatorLiteralDefinitionTest, Construct) {
    OperatorLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(OperatorLiteralDefinitionTest, CreateInstanceNative) {
    OperatorLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance("+")) != nullptr);

    LiteralPointer literal = definition.createInstance("+");
    EXPECT_EQ("+", literal->toString());
}

TEST(OperatorLiteralDefinitionTest, CreateInstance) {
    OperatorLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(definition.createInstance("FOO")) != nullptr);

    LiteralPointer literal = definition.createInstance("FOO");
    EXPECT_EQ("FOO", literal->toString());
}
