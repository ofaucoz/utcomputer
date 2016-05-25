#ifndef LO21_RESOLVER_H
#define LO21_RESOLVER_H


#include <iostream>
#include "operator/interface.h"
#include "literal/numeric.h"
#include "literal_definition/operator.h"

using namespace std;

/*
 * The resolver uses the table of variables and the table of programs
 * to replace AtomLiterals by their equivalent numeric or operator literals.
 */
class Resolver {
private:
    const OperatorMap& operatorsMap;
    const ProgramMap& programsMap;
    const VariableMap& variablesMap;

    const OperatorLiteralDefinition& operatorLiteralDefinition;

public:
    Resolver(const OperatorMap& operatorsMap,
             const ProgramMap& programsMap,
             const VariableMap& variablesMap,
             const OperatorLiteralDefinition& operatorLiteralDefinition) :
        operatorsMap(operatorsMap),
        programsMap(programsMap),
        variablesMap(variablesMap),
        operatorLiteralDefinition(operatorLiteralDefinition) { }

    LiteralVector resolve(LiteralVector tokens) const;
};


#endif //LO21_RESOLVER_H
