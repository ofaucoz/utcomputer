#include <gtest/gtest.h>
#include "../../literal_definition/atom.h"

TEST(AtomLiteralDefinitionTest, Construct) {
    AtomLiteralDefinition definition;

    ASSERT_GT(definition.getPattern().size(), 2);
}

TEST(AtomLiteralDefinitionTest, CreateInstance) {
    AtomLiteralDefinition definition;

    ASSERT_TRUE(dynamic_pointer_cast<AtomLiteral>(definition.createInstance("FOO")) != nullptr);

    LiteralPointer literal = definition.createInstance("FOO");
    ASSERT_EQ("FOO", literal->toString());
}
