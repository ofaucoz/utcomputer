#include <gtest/gtest.h>
#include "../../literal_definition/atom.h"
#include "../../literal_definition/comma.h"
#include "../../literal_definition/whitespace.h"
#include "../../literal_definition/numeric.h"
#include "../../literal_definition/operator_numeric.h"
#include "../../literal_definition/expression.h"
#include "../../literal_definition/program.h"
#include "../../literal_definition/parenthesis.h"
#include "../../serializer/literals_stack.h"

TEST(LiteralsStackSerializer, Serialize) {
    LiteralsStackSerializer serializer;
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new CommaLiteralDefinition());
    serializer.addDefinition(new ParenthesisLiteralDefinition());
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new NumericLiteralDefinition());
    serializer.addDefinition(new OperatorNumericLiteralDefinition());
    serializer.addDefinition(new ExpressionLiteralDefinition());
    serializer.addDefinition(new ProgramLiteralDefinition());
    serializer.addDefinition(new AtomLiteralDefinition());

    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(1, 2, 3, 4)));
    stack.push(LiteralPointer(new AtomLiteral("FOO")));
    stack.push(LiteralPointer(new CommaLiteral()));
    stack.push(LiteralPointer(new ExpressionLiteral("'BAR'")));
    stack.push(LiteralPointer(new OperatorLiteral("+")));
    stack.push(LiteralPointer(new ParenthesisLiteral("(")));
    stack.push(LiteralPointer(new ProgramLiteral("[ A B + ]")));
    stack.push(LiteralPointer(new WhitespaceLiteral()));

    string serialized = serializer.serialize(stack);
    EXPECT_EQ(
        "[\"numeric:1/2$3/4\",\"atom:FOO\",\"comma\",\"expression:'BAR'\",\"operator:+\",\"parenthesis:(\",\"program:[ A B + ]\",\"whitespace\"]",
        serialized);

    LiteralsStack unserialized = serializer.unserialize(serialized);
    EXPECT_EQ(stack.size(), unserialized.size());
    EXPECT_EQ(stack.top()->toString(), unserialized.top()->toString());
    EXPECT_EQ(stack.second()->toString(), unserialized.second()->toString());
}
