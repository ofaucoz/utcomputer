#include <gtest/gtest.h>
#include "../../operator/program_if.h"
#include "../../literal_definition/operator_equal_comparison.h"
#include "../../literal_definition/operator_strict_comparison.h"
#include "../../literal_definition/operator_atom_literal.h"
#include "../../operator/interface.h"
#include "../../operator/addition.h"
#include "../../operator/substraction.h"
#include "../../operator/division.h"
#include "../../operator/multiplication.h"
#include "../../operator/euclidian_division.h"
#include "../../operator/modulo.h"
#include "../../operator/opposite.h"
#include "../../operator/numerator.h"
#include "../../operator/denominator.h"
#include "../../operator/logic_and.h"
#include "../../operator/logic_different.h"
#include "../../operator/logic_equals.h"
#include "../../operator/logic_greater.h"
#include "../../operator/logic_greater_equals.h"
#include "../../operator/logic_lesser.h"
#include "../../operator/logic_lesser_equals.h"
#include "../../operator/logic_not.h"
#include "../../operator/logic_or.h"
#include "../../operator/numeric_complex_build.h"
#include "../../operator/numeric_complex_imaginary.h"
#include "../../operator/numeric_complex_real.h"
#include "../../operator/stack_clear.h"
#include "../../operator/stack_drop.h"
#include "../../operator/sto.h"
#include "../../operator/forget.h"
#include "../../operator/stack_dup.h"

TEST(ProgramIfOperatorTest, 1ValueAndProgram) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(1)));
    stack.push(LiteralPointer(new ProgramLiteral("[1 1 +]")));
    Lexer *lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorNumericLiteralDefinition);
    lexer->addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer->addDefinition(new OperatorStrictComparisonLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);
    
    OperatorMap operatorsMap;
    ProgramMap programsMap;
    VariableMap variablesMap;

    Resolver *resolver = new Resolver(operatorsMap, programsMap, variablesMap,
                            LiteralDefinitionPointer(new OperatorAtomLiteralDefinition));

    Runner *runner = new Runner(operatorsMap, stack);

    UTComputer *computer = new UTComputer(*lexer, *resolver, *runner);

    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("ADD", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));
    operatorsMap.set("EVAL", OperatorPointer(new EvalOperator(*computer)));
    operatorsMap.set("AND", OperatorPointer(new LogicAndOperator));
    operatorsMap.set("NOT", OperatorPointer(new LogicNotOperator));
    operatorsMap.set("OR", OperatorPointer(new LogicOrOperator));
    operatorsMap.set("!=", OperatorPointer(new LogicDifferentOperator));
    operatorsMap.set("=", OperatorPointer(new LogicEqualsOperator));
    operatorsMap.set(">", OperatorPointer(new LogicGreaterOperator));
    operatorsMap.set(">=", OperatorPointer(new LogicGreaterEqualsOperator));
    operatorsMap.set("<", OperatorPointer(new LogicLesserOperator));
    operatorsMap.set("<=", OperatorPointer(new LogicLesserEqualsOperator));
    operatorsMap.set("$", OperatorPointer(new NumericComplexBuildOperator));
    operatorsMap.set("IM", OperatorPointer(new NumericComplexImaginaryOperator));
    operatorsMap.set("RE", OperatorPointer(new NumericComplexRealOperator));
    operatorsMap.set("CLEAR", OperatorPointer(new StackClearOperator));
    operatorsMap.set("DROP", OperatorPointer(new StackDropOperator));
    operatorsMap.set("STO",OperatorPointer(new StoOperator(variablesMap,programsMap,*lexer)));
    operatorsMap.set("FORGET",OperatorPointer(new ForgetOperator(variablesMap,programsMap)));
    EvalOperator *evalOperator = new EvalOperator(*computer);
    operatorsMap.set("IFT",OperatorPointer(new ProgramIfOperator(*evalOperator)));
    operatorsMap.set("DUP",OperatorPointer(new StackDupOperator));

    EXPECT_EQ(2, stack.size());

    ProgramIfOperator programIfOperator(*evalOperator);
    programIfOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("2",stack.top()->toString());
}

TEST(ProgramIfOperatorTest, 1ValueAndExpression) {
    LiteralsStack stack;
    stack.push(LiteralPointer(new NumericLiteral(1)));
    stack.push(LiteralPointer(new ExpressionLiteral("'1+1'")));
    Lexer *lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorNumericLiteralDefinition);
    lexer->addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer->addDefinition(new OperatorStrictComparisonLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);

    OperatorMap operatorsMap;
    ProgramMap programsMap;
    VariableMap variablesMap;

    Resolver *resolver = new Resolver(operatorsMap, programsMap, variablesMap,
                                      LiteralDefinitionPointer(new OperatorAtomLiteralDefinition));

    Runner *runner = new Runner(operatorsMap, stack);

    UTComputer *computer = new UTComputer(*lexer, *resolver, *runner);

    operatorsMap.set("+", OperatorPointer(new AdditionOperator));
    operatorsMap.set("ADD", OperatorPointer(new AdditionOperator));
    operatorsMap.set("-", OperatorPointer(new SubstractionOperator));
    operatorsMap.set("/", OperatorPointer(new DivisionOperator));
    operatorsMap.set("*", OperatorPointer(new MultiplicationOperator));
    operatorsMap.set("DIV", OperatorPointer(new EuclidianDivisionOperator));
    operatorsMap.set("MOD", OperatorPointer(new ModuloOperator));
    operatorsMap.set("NEG", OperatorPointer(new OppositeOperator));
    operatorsMap.set("NUM", OperatorPointer(new NumeratorOperator));
    operatorsMap.set("DEN", OperatorPointer(new DenominatorOperator));
    operatorsMap.set("EVAL", OperatorPointer(new EvalOperator(*computer)));
    operatorsMap.set("AND", OperatorPointer(new LogicAndOperator));
    operatorsMap.set("NOT", OperatorPointer(new LogicNotOperator));
    operatorsMap.set("OR", OperatorPointer(new LogicOrOperator));
    operatorsMap.set("!=", OperatorPointer(new LogicDifferentOperator));
    operatorsMap.set("=", OperatorPointer(new LogicEqualsOperator));
    operatorsMap.set(">", OperatorPointer(new LogicGreaterOperator));
    operatorsMap.set(">=", OperatorPointer(new LogicGreaterEqualsOperator));
    operatorsMap.set("<", OperatorPointer(new LogicLesserOperator));
    operatorsMap.set("<=", OperatorPointer(new LogicLesserEqualsOperator));
    operatorsMap.set("$", OperatorPointer(new NumericComplexBuildOperator));
    operatorsMap.set("IM", OperatorPointer(new NumericComplexImaginaryOperator));
    operatorsMap.set("RE", OperatorPointer(new NumericComplexRealOperator));
    operatorsMap.set("CLEAR", OperatorPointer(new StackClearOperator));
    operatorsMap.set("DROP", OperatorPointer(new StackDropOperator));
    operatorsMap.set("STO",OperatorPointer(new StoOperator(variablesMap,programsMap,*lexer)));
    operatorsMap.set("FORGET",OperatorPointer(new ForgetOperator(variablesMap,programsMap)));
    EvalOperator *evalOperator = new EvalOperator(*computer);
    operatorsMap.set("IFT",OperatorPointer(new ProgramIfOperator(*evalOperator)));
    operatorsMap.set("DUP",OperatorPointer(new StackDupOperator));

    EXPECT_EQ(2, stack.size());

    ProgramIfOperator programIfOperator(*evalOperator);
    programIfOperator.apply(stack);

    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("2",stack.top()->toString());
}
