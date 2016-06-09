#include <gtest/gtest.h>
#include "../../literal_definition/atom.h"
#include "../../literal_definition/comma.h"
#include "../../literal_definition/whitespace.h"
#include "../../literal_definition/numeric.h"
#include "../../literal_definition/operator_numeric.h"
#include "../../literal_definition/expression.h"
#include "../../literal_definition/program.h"
#include "../../literal_definition/parenthesis.h"
#include "../../serializer/programs_map.h"

TEST(ProgramsMapSerializer, Serialize) {
    ProgramsMapSerializer serializer;
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new CommaLiteralDefinition());
    serializer.addDefinition(new ParenthesisLiteralDefinition());
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new NumericLiteralDefinition());
    serializer.addDefinition(new OperatorNumericLiteralDefinition());
    serializer.addDefinition(new ExpressionLiteralDefinition());
    serializer.addDefinition(new ProgramLiteralDefinition());
    serializer.addDefinition(new AtomLiteralDefinition());

    ProgramMap programMap;
    LiteralVector program;

    program.push_back(LiteralPointer(new NumericLiteral(1, 2, 3, 4)));
    program.push_back(LiteralPointer(new AtomLiteral("FOO")));
    program.push_back(LiteralPointer(new CommaLiteral()));
    program.push_back(LiteralPointer(new ExpressionLiteral("'BAR'")));
    program.push_back(LiteralPointer(new OperatorLiteral("+")));
    program.push_back(LiteralPointer(new ParenthesisLiteral("(")));
    program.push_back(LiteralPointer(new ProgramLiteral("[ A B + ]")));
    program.push_back(LiteralPointer(new WhitespaceLiteral()));

    programMap["PROG"] = program;

    string serialized = serializer.serialize(programMap);
    EXPECT_EQ(
        "{\"PROG\":[\"numeric:1/2$3/4\",\"atom:FOO\",\"comma\",\"expression:'BAR'\",\"operator:+\",\"parenthesis:(\",\"program:[ A B + ]\",\"whitespace\"]}",
        serialized);

    ProgramMap unserialized = serializer.unserialize(serialized);
    EXPECT_EQ(programMap.size(), unserialized.size());
    EXPECT_EQ(programMap["PROG"].size(), unserialized["PROG"].size());
}
