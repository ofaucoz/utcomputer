#include <iostream>
#include "lib/utcomputer.h"

using namespace std;

int main() {
    /*
     * Lexer
     */
    AtomLiteralDefinition atomLiteralDefinition;
    WhitespaceLiteralDefinition whitespaceLiteralDefinition;
    NumericLiteralDefinition numLiteralDefinition;
    OperatorLiteralDefinition operatorLiteralDefinition;
    ExpressionLiteralDefinition expressionLiteralDefinition;
    ProgramLiteralDefinition programLiteralDefinition;

    Lexer lexer;
    lexer.addDefinition(whitespaceLiteralDefinition);
    lexer.addDefinition(numLiteralDefinition);
    lexer.addDefinition(operatorLiteralDefinition);
    lexer.addDefinition(expressionLiteralDefinition);
    lexer.addDefinition(programLiteralDefinition);
    lexer.addDefinition(atomLiteralDefinition);

    /*
     * Resolver
     */
    OperatorsRepository operatorsRepository;
    ProgramsRepository programsRepository;
    VariablesRepository variablesRepository;

    Resolver resolver(operatorsRepository, programsRepository, variablesRepository, operatorLiteralDefinition);

    /*
     * Runner
     */
    Runner runner;

    /*
     * Application
     */
    UTComputer computer(lexer, resolver, runner);

    computer.execute("36 -2/4 + 6$4 * 98/2$-55/4 +");

    return 0;
}
