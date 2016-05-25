#include <gtest/gtest.h>
#include "../../literal_definition/whitespace.h"

TEST(WhitespaceLiteralDefinitionTest, Construct) {
    WhitespaceLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(WhitespaceLiteralDefinitionTest, CreateInstance) {
    WhitespaceLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(definition.createInstance(" ")) != nullptr);

    LiteralPointer literal = dynamic_pointer_cast<WhitespaceLiteral>(definition.createInstance(" \t\n"));
    EXPECT_EQ(" ", literal->toString());
}
