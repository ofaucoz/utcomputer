#include <gtest/gtest.h>
#include "../../literal_definition/parenthesis.h"

TEST(ParenthesisLiteralDefinitionTest, Construct) {
    ParenthesisLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(ParenthesisLiteralDefinitionTest, CreateInstance) {
    ParenthesisLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<ParenthesisLiteral>(definition.createInstance("(")) != nullptr);

    LiteralPointer literal = dynamic_pointer_cast<ParenthesisLiteral>(definition.createInstance(")"));
    EXPECT_EQ(")", literal->toString());
}
