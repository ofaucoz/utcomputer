#include <gtest/gtest.h>
#include "../../literal_definition/expression.h"

TEST(ExpressionLiteralDefinitionTest, Construct) {
    ExpressionLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(ExpressionLiteralDefinitionTest, CreateInstance) {
    ExpressionLiteralDefinition definition;

    ASSERT_TRUE(dynamic_cast<ExpressionLiteral*>(definition.createInstance("FOO")) != nullptr);

    LiteralInterface* literal = definition.createInstance("FOO");
    ASSERT_EQ("FOO", literal->toString());
}