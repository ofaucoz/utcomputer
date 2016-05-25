#ifndef LO21_RUNNER_H
#define LO21_RUNNER_H


#include <iostream>
#include "operator/interface.h"

using namespace std;

/*
 * The runner executes a list of literals and apply the changes to the stack
 * using the operators objects.
 */
class Runner {
private:
    const OperatorMap& operatorsMap;
    LiteralsStack& literalStack;

public:
    Runner(const OperatorMap& operatorsMap, LiteralsStack& literalStack) :
        operatorsMap(operatorsMap), literalStack(literalStack) { }

    void run(LiteralVector resolvedTokens);
};


#endif //LO21_RUNNER_H
