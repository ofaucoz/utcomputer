#include <gtest/gtest.h>
#include "../lexer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/operator.h"
#include "../literal_definition/expression.h"
#include "../literal_definition/program.h"

TEST(LexerTest, Tokenize) {
    Lexer lexer;

    lexer.addDefinition(new WhitespaceLiteralDefinition());
    lexer.addDefinition(new NumericLiteralDefinition());
    lexer.addDefinition(new OperatorLiteralDefinition());
    lexer.addDefinition(new ExpressionLiteralDefinition());
    lexer.addDefinition(new ProgramLiteralDefinition());
    lexer.addDefinition(new AtomLiteralDefinition());

    LiteralVector tokens = lexer.tokenize("FOO 36 -2/4 6$4 98/2$-55/4 + - * / EVAL '3+3*56' [1 +]");

    // Check the built tokens
    EXPECT_TRUE(dynamic_pointer_cast<AtomLiteral>(tokens[0]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[1]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(tokens[2]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[3]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(tokens[4]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[5]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(tokens[6]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[7]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(tokens[8]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[9]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(tokens[10]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[11]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(tokens[12]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[13]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(tokens[14]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[15]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(tokens[16]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[17]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<AtomLiteral>(tokens[18]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[19]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<ExpressionLiteral>(tokens[20]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(tokens[21]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<ProgramLiteral>(tokens[22]) != nullptr);
}

TEST(LexerTest, TokenizeFailure) {
    Lexer lexer;

    EXPECT_THROW(lexer.tokenize("FOO"), InvalidSyntaxException);

    lexer.addDefinition(new AtomLiteralDefinition());

    EXPECT_NO_THROW(lexer.tokenize("FOO"));
    EXPECT_THROW(lexer.tokenize("34"), InvalidSyntaxException);
}
