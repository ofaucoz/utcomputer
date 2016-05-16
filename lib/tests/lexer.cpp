#include <gtest/gtest.h>
#include "../lexer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/operator.h"
#include "../literal_definition/expression.h"
#include "../literal_definition/program.h"

TEST(LexerTest, Tokenize) {
    AtomLiteralDefinition atomLiteralDefinition;
    WhitespaceLiteralDefinition whitespaceLiteralDefinition;
    NumericLiteralDefinition numLiteralDefinition;
    OperatorLiteralDefinition operatorLiteralDefinition;
    ExpressionLiteralDefinition expressionLiteralDefinition;
    ProgramLiteralDefinition programLiteralDefinition;

    Lexer lexer;

    lexer.addDefinition(whitespaceLiteralDefinition);
    lexer.addDefinition(numLiteralDefinition);
    lexer.addDefinition(operatorLiteralDefinition);
    lexer.addDefinition(expressionLiteralDefinition);
    lexer.addDefinition(programLiteralDefinition);
    lexer.addDefinition(atomLiteralDefinition);

    vector<LiteralInterface*> tokens = lexer.tokenize("FOO 36 -2/4 6$4 98/2$-55/4 + - * / EVAL '3+3*56' [1 +]");

    // Check the built tokens
    ASSERT_TRUE(dynamic_cast<AtomLiteral*>(tokens[0]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[1]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(tokens[2]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[3]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(tokens[4]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[5]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(tokens[6]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[7]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(tokens[8]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[9]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(tokens[10]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[11]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(tokens[12]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[13]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(tokens[14]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[15]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(tokens[16]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[17]) != nullptr);
    ASSERT_TRUE(dynamic_cast<AtomLiteral*>(tokens[18]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[19]) != nullptr);
    ASSERT_TRUE(dynamic_cast<ExpressionLiteral*>(tokens[20]) != nullptr);
    ASSERT_TRUE(dynamic_cast<WhitespaceLiteral*>(tokens[21]) != nullptr);
    ASSERT_TRUE(dynamic_cast<ProgramLiteral*>(tokens[22]) != nullptr);
}

TEST(LexerTest, TokenizeFailure) {
    AtomLiteralDefinition atomLiteralDefinition;
    Lexer lexer;

    ASSERT_THROW(lexer.tokenize("FOO"), InvalidSyntaxException);

    lexer.addDefinition(atomLiteralDefinition);

    ASSERT_NO_THROW(lexer.tokenize("FOO"));
    ASSERT_THROW(lexer.tokenize("34"), InvalidSyntaxException);
}
