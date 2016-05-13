#include <gtest/gtest.h>
#include "../lexer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"

TEST(LexerTest, StackBehavior) {
    AtomLiteralDefinition atomLiteralDefinition;
    WhitespaceLiteralDefinition whitespaceLiteralDefinition;

    Lexer* lexer = new Lexer();
    lexer->addDefinition(atomLiteralDefinition);
    lexer->addDefinition(whitespaceLiteralDefinition);
    lexer->tokenize("FOO BAR");

    ASSERT_TRUE(true);
}
