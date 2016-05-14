#include <gtest/gtest.h>
#include "../lexer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"

TEST(LexerTest, StackBehavior) {
    AtomLiteralDefinition atomLiteralDefinition;
    WhitespaceLiteralDefinition whitespaceLiteralDefinition;
    NumericLiteralDefinition numLiteralDefinition;

    Lexer* lexer = new Lexer();
    lexer->addDefinition(atomLiteralDefinition);
    lexer->addDefinition(whitespaceLiteralDefinition);
    lexer->addDefinition(numLiteralDefinition);
    lexer->tokenize("FOO BAR 98");
    lexer->tokenize("FOO BAR 35/5");
    lexer->tokenize("FOO BAR 98$58");
    lexer->tokenize("FOO BAR 98/2$55/4");
    lexer->tokenize("FOO BAR 98$55/9");
    lexer->tokenize("FOO BAR 0$5");
    lexer->tokenize("FOO BAR 0$5/2");

    ASSERT_TRUE(true);
}
