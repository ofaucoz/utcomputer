#ifndef LO21_RUNNER_H
#define LO21_RUNNER_H


#include <iostream>
#include "operator/interface.h"

using namespace std;

/**
 * The Runner is the third and last main component of the UTComputer library.
 *
 * Called after the Resolver, its role is to apply the command to the stack.
 *
 * It uses the operators list to execute actions on the stack and it pushes
 * other literals on top of it.
 */
class Runner {
private:
    const OperatorMap &operatorsMap;
    LiteralsStack &literalStack;

public:
    /**
     * The Runner uses the operators list to apply operations on the stack.
     *
     * @param operatorsMap The operators hashmap.
     * @param literalStack The stack of literals to compute and return a result.
     */
    Runner(const OperatorMap &operatorsMap, LiteralsStack &literalStack) :
        operatorsMap(operatorsMap), literalStack(literalStack) { }

    /**
     * This is the main method of the Runner.
     *
     * Using the operators list and the provided literals, the runner applies
     * the asked operations to the stack.
     *
     * If an unkown literal that can't be handled is found, it throws an
     * UnsupportedLiteralException.
     *
     * @throws UnsupportedLiteralException
     * @param resolvedTokens A list of literals (usually coming from the Lexer).
     * @return A simpler list of literals without atom literals.
     */
    void run(LiteralVector resolvedTokens);
};


#endif //LO21_RUNNER_H
