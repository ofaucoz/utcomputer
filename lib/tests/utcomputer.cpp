#include <gtest/gtest.h>
#include "../utcomputer.h"
#include "../literal_definition/atom.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/expression.h"
#include "../literal_definition/operator_numeric.h"
#include "../literal_definition/program.h"
#include "../operator/addition.h"
#include "../operator/substraction.h"
#include "../operator/division.h"
#include "../operator/multiplication.h"
#include "../operator/denominator.h"
#include "../operator/numerator.h"
#include "../operator/modulo.h"
#include "../operator/euclidian_division.h"
#include "../operator/opposite.h"
#include "../operator/eval.h"

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
    lexer.addDefinition(new WhitespaceLiteralDefinition);
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorNumericLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    /*
     * Resolver
     */
    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorNumericLiteralDefinition));

    /*
     * Runner
     */
    Runner runner(operatorsMap, stack);

    /*
     * Application
     */
    UTComputer computer(lexer, resolver, runner);

    operatorsMap.set("EVAL", OperatorPointer(new EvalOperator(computer)));

    // Addition
    computer.execute("3 4 +");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("7", stack.top()->toString());

    // Substraction
    computer.execute("5 -");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("2", stack.top()->toString());

    // Division
    computer.execute("2 /");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Multiplication
    computer.execute("5 *");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("5", stack.top()->toString());

    // Euclidian division
    computer.execute("2 DIV");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("2", stack.top()->toString());

    // Multiplication
    computer.execute("4.5 *");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("9", stack.top()->toString());

    // Modulo
    computer.execute("4 MOD");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Modulo
    computer.execute("4 MOD");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Opposite
    computer.execute("NEG");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("-1", stack.top()->toString());

    // Numerator
    computer.execute("3/4 NUM");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("3", stack.top()->toString());

    // Denominator
    computer.execute("2.4/4.8 DEN");
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("4.800000", stack.top()->toString());

    // Addition
    computer.execute("+");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("7.800000", stack.top()->toString());

    // Addition
    computer.execute("+");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("6.800000", stack.top()->toString());

    // Eval simple
    computer.execute("'3+6' EVAL");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("9", stack.top()->toString());

    // Eval complex
    computer.execute("'DIV(9,NEG(-2))+4' EVAL");
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("8", stack.top()->toString());


    // Variables
    variablesMap.set("FOO", NumericLiteralPointer(new NumericLiteral(12)));
    computer.execute("9 FOO +");
    EXPECT_EQ(4, stack.size());
    EXPECT_EQ("21", stack.top()->toString());
}
