#include <gtest/gtest.h>
#include "../../literal_definition/operator.h"

TEST(OperatorLiteralDefinitionTest, Construct) {
    OperatorLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(OperatorLiteralDefinitionTest, CreateInstanceNative) {
    OperatorLiteralDefinition definition;

    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(definition.createInstance("+")) != nullptr);

    LiteralInterface* literal = definition.createInstance("+");
    ASSERT_EQ("+", literal->toString());
}

TEST(OperatorLiteralDefinitionTest, CreateInstance) {
    OperatorLiteralDefinition definition;

    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(definition.createInstance("FOO")) != nullptr);

    LiteralInterface* literal = definition.createInstance("FOO");
    ASSERT_EQ("FOO", literal->toString());
}