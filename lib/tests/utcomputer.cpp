#include <gtest/gtest.h>
#include "../utcomputer.h"
#include "../literal_definition/whitespace.h"
#include "../literal_definition/numeric.h"
#include "../literal_definition/operator_numeric.h"
#include "../literal_definition/operator_strict_comparison.h"
#include "../literal_definition/operator_equal_comparison.h"
#include "../literal_definition/expression.h"
#include "../literal_definition/program.h"
#include "../literal_definition/atom.h"
#include "../operator/addition.h"
#include "../operator/substraction.h"
#include "../operator/division.h"
#include "../operator/multiplication.h"
#include "../operator/euclidian_division.h"
#include "../operator/modulo.h"
#include "../operator/opposite.h"
#include "../operator/numerator.h"
#include "../operator/denominator.h"
#include "../operator/eval.h"
#include "../operator/logic_and.h"
#include "../operator/logic_different.h"
#include "../operator/logic_equals.h"
#include "../operator/numeric_greater.h"
#include "../operator/numeric_greater_equals.h"
#include "../operator/numeric_lesser.h"
#include "../operator/numeric_lesser_equals.h"
#include "../operator/logic_not.h"
#include "../operator/logic_or.h"
#include "../operator/numeric_complex_build.h"
#include "../operator/numeric_complex_imaginary.h"
#include "../operator/numeric_complex_real.h"
#include "../operator/stack_clear.h"
#include "../operator/stack_drop.h"
#include "../operator/stack_undo.h"
#include "../operator/stack_redo.h"
#include "../operator/stack_swap.h"

TEST(UTComputer, FunctionnalTest) {
    // Stack
    LiteralsStack stack;

    // Operators
    OperatorMap operatorsMap;

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
    lexer.addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer.addDefinition(new OperatorStrictComparisonLiteralDefinition);
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

    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));
    operatorsMap.set("EVAL", OperatorPointer(new EvalOperator(computer)));
    operatorsMap.set("AND", OperatorPointer(new LogicAndOperator));
    operatorsMap.set("NOT", OperatorPointer(new LogicNotOperator));
    operatorsMap.set("OR", OperatorPointer(new LogicOrOperator));
    operatorsMap.set("!=", OperatorPointer(new LogicDifferentOperator));
    operatorsMap.set("=", OperatorPointer(new LogicEqualsOperator));
    operatorsMap.set(">", OperatorPointer(new NumericGreaterOperator));
    operatorsMap.set(">=", OperatorPointer(new NumericGreaterEqualsOperator));
    operatorsMap.set("<", OperatorPointer(new NumericLesserOperator));
    operatorsMap.set("<=", OperatorPointer(new NumericLesserEqualsOperator));
    operatorsMap.set("$", OperatorPointer(new NumericComplexBuildOperator));
    operatorsMap.set("IM", OperatorPointer(new NumericComplexImaginaryOperator));
    operatorsMap.set("RE", OperatorPointer(new NumericComplexRealOperator));
    operatorsMap.set("CLEAR", OperatorPointer(new StackClearOperator));
    operatorsMap.set("DROP", OperatorPointer(new StackDropOperator));
    operatorsMap.set("UNDO", OperatorPointer(new StackUndoOperator));
    operatorsMap.set("REDO", OperatorPointer(new StackRedoOperator));
    operatorsMap.set("SWAP", OperatorPointer(new StackSwapOperator));

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

    // Clear
    computer.execute("CLEAR");
    EXPECT_EQ(0, stack.size());

    // And
    computer.execute("1 1 AND");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Or
    computer.execute("0 OR");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Equals
    computer.execute("1 =");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Different
    computer.execute("1 !=");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());

    // Greater
    computer.execute("4 >");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());

    // Greater or equals
    computer.execute("0 >=");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Less or equals
    computer.execute("1 <=");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Less
    computer.execute("1 <");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0", stack.top()->toString());

    // Build complex
    computer.execute("4 $");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("0$4", stack.top()->toString());

    // Imaginary part
    computer.execute("IM");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());

    // Real part
    computer.execute("6/7$8 RE");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("6/7", stack.top()->toString());

    // Drop
    computer.execute("DROP");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());

    // Undo
    computer.execute("UNDO");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("6/7", stack.top()->toString());

    // Redo
    computer.execute("REDO");
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("4", stack.top()->toString());

    // Clear
    computer.execute("CLEAR");
    EXPECT_EQ(0, stack.size());

    // Swap
    computer.execute("1");
    computer.execute("4");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
    computer.execute("SWAP");
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("1", stack.top()->toString());

    // Variables
    variablesMap.set("FOO", NumericLiteralPointer(new NumericLiteral(12)));
    computer.execute("9 FOO +");
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("21", stack.top()->toString());
}
