#include <gtest/gtest.h>
#include "../utcomputer.h"
#include "../operator/addition.h"
#include "../operator/substraction.h"
#include "../operator/division.h"
#include "../operator/multiplication.h"
#include "../operator/denominator.h"
#include "../operator/numerator.h"
#include "../operator/modulo.h"
#include "../operator/euclidian_division.h"
#include "../operator/opposite.h"

TEST(UTComputer, FunctionnalTest) {
    // Stack
    LiteralsStack stack;

    // Operators
    OperatorMap operatorsMap;
    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));

    // Programs
    ProgramMap programsMap;

    // Variables
    VariableMap variablesMap;

    /*
     * Lexer
     */
    Lexer lexer;
    lexer.addDefinition(new WhitespaceLiteralDefinition());
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    /*
     * Resolver
     */
    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));

    /*
     * Runner
     */
    Runner runner(operatorsMap, stack);

    /*
     * Application
     */
    UTComputer computer(lexer, resolver, runner);


    /*
     * Test operators
     */

    // Addition
    computer.execute("3 4 +");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("7", stack.top()->toString());

    // Substraction
    computer.execute("5 -");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("2", stack.top()->toString());

    // Division
    computer.execute("2 /");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("1", stack.top()->toString());

    // Multiplication
    computer.execute("5 *");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("5", stack.top()->toString());

    // Euclidian division
    computer.execute("2 DIV");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("2", stack.top()->toString());

    // Multiplication
    computer.execute("4.5 *");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("9", stack.top()->toString());

    // Modulo
    computer.execute("4 MOD");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("1", stack.top()->toString());

    // Modulo
    computer.execute("4 MOD");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("1", stack.top()->toString());

    // Opposite
    computer.execute("NEG");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("-1", stack.top()->toString());

    // Numerator
    computer.execute("3/4 NUM");
    ASSERT_EQ(2, stack.size());
    ASSERT_EQ("3", stack.top()->toString());

    // Denominator
    computer.execute("2.4/4.8 DEN");
    ASSERT_EQ(3, stack.size());
    ASSERT_EQ("4.800000", stack.top()->toString());

    // Addition
    computer.execute("+");
    ASSERT_EQ(2, stack.size());
    ASSERT_EQ("7.800000", stack.top()->toString());

    // Addition
    computer.execute("+");
    ASSERT_EQ(1, stack.size());
    ASSERT_EQ("6.800000", stack.top()->toString());
}
