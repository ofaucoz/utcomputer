#include <gtest/gtest.h>
#include "../../literal_definition/program.h"

TEST(ProgramLiteralDefinitionTest, Construct) {
    ProgramLiteralDefinition definition;

    EXPECT_GT(definition.getPattern().size(), 2);
}

TEST(ProgramLiteralDefinitionTest, CreateInstanceNative) {
    ProgramLiteralDefinition definition;

    EXPECT_TRUE(dynamic_pointer_cast<ProgramLiteral>(definition.createInstance("[3 2 +]")) != nullptr);

    LiteralPointer literal = definition.createInstance("[3 2 +]");
    EXPECT_EQ("[3 2 +]", literal->toString());
}
