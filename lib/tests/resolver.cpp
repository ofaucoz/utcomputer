#include <gtest/gtest.h>
#include "../resolver.h"
#include "../operator/plus.h"
#include "../literal/atom.h"
#include "../debug/tokens_dumper.h"

TEST(ResolverTest, Resolve) {
    NumericLiteral literal1(2);
    AtomLiteral literal2("FOO");
    AtomLiteral literal3("ADD");
    NumericLiteral literal4(4, 5);
    AtomLiteral literal5("BAR");
    OperatorLiteral literal6("+");

    // Operators repository
    PlusOperator plusOperator;

    OperatorsRepository operatorsRepository;
    operatorsRepository.set("ADD", plusOperator);

    // Programs repository
    ProgramsRepository programsRepository;

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

    LiteralVector resolved = resolver.resolve(vector);

    TokensDumper::dump(cout, resolved);

    ASSERT_TRUE(true);
}
