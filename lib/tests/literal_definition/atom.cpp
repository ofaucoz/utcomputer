#include <gtest/gtest.h>
#include "../../literal_definition/atom.h"

TEST(AtomLiteralDefinitionTest, Construct) {
    AtomLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(AtomLiteralDefinitionTest, CreateInstance) {
    AtomLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<AtomLiteral>(definition.createInstance("FOO")) != nullptr);

    LiteralPointer literal = definition.createInstance("FOO");
    EXPECT_EQ("FOO", literal->toString());
}
