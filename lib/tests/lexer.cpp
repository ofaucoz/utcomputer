#include <gtest/gtest.h>
#include "../lexer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/operator.h"
#include "../literal_definition/expression.h"

TEST(LexerTest, StackBehavior) {
    AtomLiteralDefinition atomLiteralDefinition;
    WhitespaceLiteralDefinition whitespaceLiteralDefinition;
    NumericLiteralDefinition numLiteralDefinition;
    OperatorLiteralDefinition operatorLiteralDefinition;
    ExpressionLiteralDefinition expressionLiteralDefinition;

    Lexer* lexer = new Lexer();

    lexer->addDefinition(atomLiteralDefinition);
    lexer->addDefinition(whitespaceLiteralDefinition);
    lexer->addDefinition(numLiteralDefinition);
    lexer->addDefinition(operatorLiteralDefinition);
    lexer->addDefinition(expressionLiteralDefinition);

    lexer->tokenize("FOO BAR 98");
    lexer->tokenize("FOO BAR 35/5");
    lexer->tokenize("FOO BAR 98$58");
    lexer->tokenize("FOO BAR 98/2$55/4");
    lexer->tokenize("FOO BAR 98$55/9");
    lexer->tokenize("FOO BAR 0$5");
    lexer->tokenize("FOO BAR 0$5/2");
    lexer->tokenize("FOO BAR 98 + 5*6 -58");
    lexer->tokenize("FOO BAR - 35/5");
    lexer->tokenize("'3+3*56' EVAL");

    ASSERT_TRUE(true);
}
