#ifndef LO21_UTCOMPUTER_H
#define LO21_UTCOMPUTER_H


#include <iostream>
#include "lexer.h"
#include "resolver.h"
#include "runner.h"
#include "literal_definition/atom.h"
#include "literal_definition/whitespace.h"
#include "literal_definition/numeric.h"
#include "literal_definition/operator.h"
#include "literal_definition/expression.h"
#include "literal_definition/program.h"
#include "debug/tokens_dumper.h"

using namespace std;

/*
 * This class is the main entrypoint of the UTComputer library.
 * It will be used by the User Interface to execute operations.
 * This library does not return any value : to display the results,
 * the User Interface needs to observe the model (the repositories).
 */
class UTComputer {
private:
    Lexer lexer;
    Resolver resolver;
    Runner runner;

public:
    UTComputer(Lexer lexer, Resolver resolver, Runner runner): lexer(lexer), resolver(resolver), runner(runner) {}

    void execute(string command) {
        LiteralVector tokens = lexer.tokenize(command);

        TokensDumper::dump(cout, tokens);

        // literals = resolver.resolve(tokens)
        // runner.applyChanges(literals)
    }
};


#endif // LO21_UTCOMPUTER_H
