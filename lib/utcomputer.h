#ifndef LO21_UTCOMPUTER_H
#define LO21_UTCOMPUTER_H


#include <iostream>
#include "lexer.h"
#include "resolver.h"
#include "runner.h"
#include "exception/undefined_atom.h"
#include "exception/invalid_syntax.h"
#include "exception/invalid_operand.h"

using namespace std;

/**
 * This class is the main entrypoint of the UTComputer library.
 *
 * It encapsulates the Lexer, the Resolver and the Runner to fully
 * execute a string command. It can also handle already parsed
 * commands (for instance, literals provided by the Eval operator).
 *
 * This class does not return any value : it will change the models
 * data and therefore the results will be provided using the Observer
 * design pattern.
 */
class UTComputer {
private:
    const Lexer &lexer;
    const Resolver &resolver;
    Runner &runner;

public:
    /**
     * The UTComputer class encapsulates the three main components of the library.
     *
     * @param lexer The Lexer to use.
     * @param resolver The Resolver to use.
     * @param runner The Runner to use.
     */
    UTComputer(const Lexer &lexer, const Resolver &resolver, Runner &runner) :
        lexer(lexer), resolver(resolver), runner(runner) { }

    /**
     * Return the Lexer (used by the Eval operator).
     *
     * @return The Lexer of this UTComputer instance.
     */
    const Lexer &getLexer() const {
        return lexer;
    }

    /**
     * Return the Resolver (used by the Eval operator).
     *
     * @return The Resolver of this UTComputer instance.
     */
    const Resolver &getResolver() const {
        return resolver;
    }

    /**
     * Execute a command given as a string.
     *
     * This will tokenize the command using the Lexer, resolves the atoms
     * of this command using the Resolver and apply the command to the stack
     * using the Runner.
     *
     * @throws InvalidSyntaxException When the given command has an invalid syntax.
     * @throws UndefinedAtomException When there is an undefined atom used in the command.
     * @throws UnsupportedLiteralException When a literal that can't be handled by the runner is found.
     * @param command The command to execute.
     */
    void execute(string command) {

        /*
         * The Lexer tokenizes the command. It creates a list of tokens
         * by splitting the given string into independant elements.
         */
        execute(lexer.tokenize(command));

    }

    /**
     * Execute a command given as an already parsed list of tokens.
     * This methods acts as `execute` with a string but skips the
     * Lexer part.
     *
     * @throws UndefinedAtomException When there is an undefined atom used in the command.
     * @throws UnsupportedLiteralException When a literal that can't be handled by the runner is found.
     * @param tokens The list of literals to execute.
     */
    void execute(LiteralVector tokens) {

        /*
         * The tokens from the Lexer can be of various types. To execute
         * the command, we need to resolve the atom tokens to variables,
         * programs and operators. The Resolver does this.
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
