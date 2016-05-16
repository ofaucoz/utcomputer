#ifndef LO21_UTCOMPUTER_H
#define LO21_UTCOMPUTER_H


#include <iostream>
#include "lexer.h"
#include "resolver.h"
#include "runner.h"

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
        // rawLiterals = lexer.tokenize(command)
        // resolvedLiterals = resolver.resolve(rawLiterals)
        // runner.applyChanges(resolvedLiterals)
    }
};


#endif // LO21_UTCOMPUTER_H
