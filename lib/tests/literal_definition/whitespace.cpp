#include <gtest/gtest.h>
#include "../../literal_definition/whitespace.h"

TEST(WhitespaceLiteralDefinitionTest, Construct) {
    WhitespaceLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(WhitespaceLiteralDefinitionTest, CreateInstance) {
    WhitespaceLiteralDefinition definition;

    ASSERT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(definition.createInstance(" ")) != nullptr);

    LiteralPointer literal = dynamic_pointer_cast<WhitespaceLiteral>(definition.createInstance(" \t\n"));
    ASSERT_EQ(" ", literal->toString());
}
