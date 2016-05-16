#include <iostream>
#include "lib/utcomputer.h"

using namespace std;

int main() {
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

    Resolver resolver;

    Runner runner;

    UTComputer computer(lexer, resolver, runner);

    computer.execute("FOO 36 -2/4 6$4 98/2$-55/4 + - * / EVAL '3+3*56' [1 +]");

    return 0;
}