#include <iostream>
#include "lib/utcomputer.h"
#include "lib/literal_definition/atom.h"
#include "lib/literal_definition/whitespace.h"
#include "lib/literal_definition/numeric.h"
#include "lib/literal_definition/expression.h"
#include "lib/literal_definition/operator.h"
#include "lib/literal_definition/program.h"
#include "lib/operator/addition.h"
#include "lib/operator/substraction.h"
#include "lib/operator/division.h"
#include "lib/operator/multiplication.h"
#include "lib/operator/denominator.h"
#include "lib/operator/numerator.h"
#include "lib/operator/modulo.h"
#include "lib/operator/euclidian_division.h"
#include "lib/operator/opposite.h"

using namespace std;

int main() {
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

    computer.execute("36.5 -2/4 + 6$4 * 98/2$-55/4 +");

    TokensDumper::dump(cout, stack);

    return 0;
}
