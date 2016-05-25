#include <gtest/gtest.h>
#include "../../literal_definition/expression.h"

TEST(ExpressionLiteralDefinitionTest, Construct) {
    ExpressionLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(ExpressionLiteralDefinitionTest, CreateInstance) {
    ExpressionLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<ExpressionLiteral>(definition.createInstance("FOO")) != nullptr);

    LiteralPointer literal = definition.createInstance("FOO");
    EXPECT_EQ("FOO", literal->toString());
}
