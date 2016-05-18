#include <gtest/gtest.h>
#include "../resolver.h"
#include "../operator/plus.h"
#include "../literal/atom.h"
#include "../exception/undefined_atom.h"

TEST(ResolverTest, Resolve) {
    NumericLiteral literal1(2);
    AtomLiteral literal2("FOO");
    AtomLiteral literal3("ADD");
    NumericLiteral literal4(4, 5);
    AtomLiteral literal5("BAR");
    OperatorLiteral literal6("+");
    AtomLiteral literal7("PROG");

    // Operators repository
    PlusOperator plusOperator;

    OperatorsRepository operatorsRepository;
    operatorsRepository.set("ADD", plusOperator);

    // Programs repository
    ProgramsRepository programsRepository;

    LiteralVector program;

    program.push_back(&literal1);
    program.push_back(&literal4);
    program.push_back(&literal6);

    programsRepository.set("PROG", program);

    // Variables repository
    VariablesRepository variablesRepository;
    variablesRepository.set("FOO", literal1);
    variablesRepository.set("BAR", literal4);

    // Operator literal definition
    OperatorLiteralDefinition operatorLiteralDefinition;

    // Resolver
    Resolver resolver(operatorsRepository, programsRepository, variablesRepository, operatorLiteralDefinition);

    // Build input vector
    LiteralVector vector;
    vector.push_back(&literal1);
    vector.push_back(&literal2);
    vector.push_back(&literal3);
    vector.push_back(&literal4);
    vector.push_back(&literal5);
    vector.push_back(&literal6);
    vector.push_back(&literal7);

    LiteralVector resolved = resolver.resolve(vector);

    // Check the resolved tokens
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[0]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[1]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(resolved[2]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[3]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[4]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(resolved[5]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[6]) != nullptr);
    ASSERT_TRUE(dynamic_cast<NumericLiteral*>(resolved[7]) != nullptr);
    ASSERT_TRUE(dynamic_cast<OperatorLiteral*>(resolved[8]) != nullptr);
}

TEST(ResolverTest, ResolveFailure) {
    OperatorsRepository operatorsRepository;
    ProgramsRepository programsRepository;
    VariablesRepository variablesRepository;
    OperatorLiteralDefinition operatorLiteralDefinition;

    Resolver resolver(operatorsRepository, programsRepository, variablesRepository, operatorLiteralDefinition);

    LiteralVector vector;
    vector.push_back(new AtomLiteral("FOO"));

    ASSERT_THROW(resolver.resolve(vector), UndefinedAtomException);
}
