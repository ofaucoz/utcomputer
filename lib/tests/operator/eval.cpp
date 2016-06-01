#include <gtest/gtest.h>
#include "../../operator/eval.h"
#include "../../operator/addition.h"
#include "../../operator/substraction.h"
#include "../../operator/division.h"
#include "../../operator/multiplication.h"
#include "../../operator/euclidian_division.h"
#include "../../operator/opposite.h"
#include "../../debug/dumper.h"

TEST(EvalOperatorTest, Postfix) {
    LiteralsStack stack;
    ProgramMap programsMap;
    VariableMap variablesMap;

    OperatorMap operatorsMap;
    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));

    Lexer lexer;
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));
    Runner runner(operatorsMap, stack);
    UTComputer computer(lexer, resolver, runner);

    EvalOperator evalOperator(computer);

    // Simple
    LiteralVector simple = evalOperator.postfix("3 * 4 + ( 11 - ( 3 * 2 ) ) / 2");
    EXPECT_EQ("3 4 * 11 3 2 * - 2 / +", Dumper::literalsToCommand(simple));

    // Variables
    LiteralVector withVariables = evalOperator.postfix("3 * 4 + ( VAR - ( 3 * FOO ) ) / 2");
    EXPECT_EQ("3 4 * VAR 3 FOO * - 2 / +", Dumper::literalsToCommand(withVariables));

    // Single operators
    LiteralVector withSingleOperators = evalOperator.postfix("(3 + 4) * NEG(NEG(2+4*5))");
    EXPECT_EQ("3 4 + 2 4 5 * + NEG NEG *", Dumper::literalsToCommand(withSingleOperators));

    // Double operators
    LiteralVector withDoubleOperators = evalOperator.postfix("(3 + 4) * DIV(DIV(4+5, 2), 5)");
    EXPECT_EQ("3 4 + 4 5 + 2 DIV 5 DIV *", Dumper::literalsToCommand(withDoubleOperators));

    // Operators and variables
    LiteralVector full = evalOperator.postfix("(3 + FOO) * DIV(DIV((BAR + 5), NEG(2)), 5)");
    EXPECT_EQ("3 FOO + BAR 5 + 2 NEG DIV 5 DIV *", Dumper::literalsToCommand(full));
}

TEST(EvalOperatorTest, Expression) {
    LiteralsStack stack;
    ProgramMap programsMap;
    VariableMap variablesMap;

    OperatorMap operatorsMap;
    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));

    Lexer lexer;
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));
    Runner runner(operatorsMap, stack);
    UTComputer computer(lexer, resolver, runner);

    stack.push(LiteralPointer(new ExpressionLiteral("'3 * 4 + ( 11 - ( 3 * 2 ) ) / 2'")));

    EXPECT_EQ(1, stack.size());

    EvalOperator evalOperator(computer);
    evalOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("29/2", stack.top()->toString());
}

TEST(EvalOperatorTest, CustomOperators) {
    LiteralsStack stack;
    ProgramMap programsMap;
    VariableMap variablesMap;

    OperatorMap operatorsMap;
    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));

    Lexer lexer;
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));
    Runner runner(operatorsMap, stack);
    UTComputer computer(lexer, resolver, runner);

    stack.push(LiteralPointer(new ExpressionLiteral("'(3 + 5) * DIV(DIV((12 + 5), NEG(2)), 5)'")));

    EXPECT_EQ(1, stack.size());

    EvalOperator evalOperator(computer);
    evalOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("-8", stack.top()->toString());
}

TEST(EvalOperatorTest, FailNonEspression) {
    LiteralsStack stack;
    ProgramMap programsMap;
    VariableMap variablesMap;

    OperatorMap operatorsMap;
    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));

    Lexer lexer;
    lexer.addDefinition(new NumericLiteralDefinition);
    lexer.addDefinition(new OperatorLiteralDefinition);
    lexer.addDefinition(new ExpressionLiteralDefinition);
    lexer.addDefinition(new ProgramLiteralDefinition);
    lexer.addDefinition(new AtomLiteralDefinition);

    Resolver resolver(operatorsMap, programsMap, variablesMap, LiteralDefinitionPointer(new OperatorLiteralDefinition));
    Runner runner(operatorsMap, stack);
    UTComputer computer(lexer, resolver, runner);

    stack.push(LiteralPointer(new NumericLiteral(3, 4, 5, 6)));

    EXPECT_EQ(1, stack.size());

    EvalOperator evalOperator(computer);
    EXPECT_THROW(evalOperator.apply(stack), InvalidOperandException);

    EXPECT_EQ(0, stack.size());
}
