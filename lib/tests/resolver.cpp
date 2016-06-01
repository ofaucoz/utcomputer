#include <gtest/gtest.h>
#include "../resolver.h"
#include "../operator/addition.h"
#include "../literal/atom.h"
#include "../literal_definition/operator.h"
#include "../exception/undefined_atom.h"

TEST(ResolverTest, Resolve) {
    // Operators messages
    OperatorMap operatorMap;
    operatorMap["ADD"] = OperatorPointer(new AdditionOperator);

    // Programs messages
    ProgramMap programMap;
    LiteralVector program;

    program.push_back(LiteralPointer(new NumericLiteral(2)));
    program.push_back(LiteralPointer(new NumericLiteral(4, 5)));
    program.push_back(LiteralPointer(new OperatorLiteral("+")));

    programMap["PROG"] = program;

    // Variables messages
    VariableMap variableMap;
    variableMap["FOO"] = LiteralPointer(new NumericLiteral(2));
    variableMap["BAR"] = LiteralPointer(new NumericLiteral(4, 5, 6, 7));

    // Resolver
    Resolver resolver(operatorMap, programMap, variableMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));

    // Build input vector
    LiteralVector tokens;
    tokens.push_back(LiteralPointer(new NumericLiteral(2)));
    tokens.push_back(LiteralPointer(new AtomLiteral("FOO")));
    tokens.push_back(LiteralPointer(new AtomLiteral("ADD")));
    tokens.push_back(LiteralPointer(new NumericLiteral(4, 5)));
    tokens.push_back(LiteralPointer(new AtomLiteral("BAR")));
    tokens.push_back(LiteralPointer(new OperatorLiteral("+")));
    tokens.push_back(LiteralPointer(new AtomLiteral("PROG")));

    LiteralVector resolved = resolver.resolve(tokens);

    // Check the resolved tokens
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[0]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[1]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(resolved[2]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[3]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[4]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(resolved[5]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[6]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<NumericLiteral>(resolved[7]) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<OperatorLiteral>(resolved[8]) != nullptr);
}

TEST(ResolverTest, ResolveFailure) {
    OperatorMap operatorMap;
    ProgramMap programMap;
    VariableMap variableMap;

    Resolver resolver(operatorMap, programMap, variableMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));

    LiteralVector vector;
    vector.push_back(LiteralPointer(new AtomLiteral("FOO")));

    EXPECT_THROW(resolver.resolve(vector), UndefinedAtomException);
}
