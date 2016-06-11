#include <gtest/gtest.h>
#include "../../literal_definition/atom.h"
#include "../../literal_definition/comma.h"
#include "../../literal_definition/whitespace.h"
#include "../../literal_definition/numeric.h"
#include "../../literal_definition/operator_numeric.h"
#include "../../literal_definition/expression.h"
#include "../../literal_definition/program.h"
#include "../../literal_definition/parenthesis.h"
#include "../../serializer/variables_map.h"

TEST(VariablesMapSerializer, Serialize) {
    VariablesMapSerializer serializer;
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new CommaLiteralDefinition());
    serializer.addDefinition(new ParenthesisLiteralDefinition());
    serializer.addDefinition(new WhitespaceLiteralDefinition());
    serializer.addDefinition(new NumericLiteralDefinition());
    serializer.addDefinition(new OperatorNumericLiteralDefinition());
    serializer.addDefinition(new ExpressionLiteralDefinition());
    serializer.addDefinition(new ProgramLiteralDefinition());
    serializer.addDefinition(new AtomLiteralDefinition());

    VariableMap variableMap;
    variableMap["A"] = LiteralPointer(new NumericLiteral(1, 2, 3, 4));
    variableMap["B"] = LiteralPointer(new AtomLiteral("FOO"));
    variableMap["C"] = LiteralPointer(new CommaLiteral());
    variableMap["D"] = LiteralPointer(new ExpressionLiteral("'BAR'"));
    variableMap["E"] = LiteralPointer(new OperatorLiteral("+"));
    variableMap["F"] = LiteralPointer(new ParenthesisLiteral("("));
    variableMap["G"] = LiteralPointer(new ProgramLiteral("[ A B + ]"));
    variableMap["H"] = LiteralPointer(new WhitespaceLiteral());

    string serialized = serializer.serialize(variableMap);
    EXPECT_EQ("{\"A\":\"numeric:1/2$3/4\",\"B\":\"atom:FOO\",\"C\":\"comma\",\"D\":\"expression:'BAR'\",\"E\":\"operator:+\",\"F\":\"parenthesis:(\",\"G\":\"program:[ A B + ]\",\"H\":\"whitespace\"}", serialized);

    VariableMap unserialized = serializer.unserialize(serialized);
    EXPECT_EQ(variableMap.size(), unserialized.size());
    EXPECT_EQ(variableMap["A"]->toString(), unserialized["A"]->toString());
    EXPECT_EQ(variableMap["F"]->toString(), unserialized["F"]->toString());
    EXPECT_EQ(variableMap["H"]->toString(), unserialized["H"]->toString());
}
