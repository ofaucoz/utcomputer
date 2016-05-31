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
#include "exception/undefined_atom.h"

using namespace std;

/*
 * This class is the main entrypoint of the UTComputer library.
 * It will be used by the User Interface to execute operations.
 * This library does not return any value : to display the results,
 * the User Interface needs to observe the model (the repositories).
 */
class UTComputer {
private:
    const Lexer& lexer;
    const Resolver& resolver;
    Runner& runner;

public:
    UTComputer(const Lexer& lexer, const Resolver& resolver, Runner& runner):
        lexer(lexer), resolver(resolver), runner(runner) {}

    void execute(string command) {

        /*
         * The Lexer tokenizes the command. It creates a list of tokens
         * by splitting the given string into independant elements.
         */
        LiteralVector tokens = lexer.tokenize(command);

        /*
         * The tokens from the lexer can be of various types. To execute
         * the command, we need to resolve the atom tokens to variables,
         * programs and operators. The Resolver do this.
         */
        LiteralVector resolved = resolver.resolve(tokens);

        /*
         * The resolved tokens are now only numeric or operator literals.
         * The Runner can be used to compute the command result.
         */
        runner.run(resolved);

    }
};


#endif // LO21_UTCOMPUTER_H
