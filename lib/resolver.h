#ifndef LO21_RESOLVER_H
#define LO21_RESOLVER_H


#include <iostream>
#include "operator/interface.h"
#include "literal/operator.h"
#include "literal/numeric.h"
#include "literal_definition/interface.h"

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
    const LiteralDefinitionPointer operatorLiteralDefinition;

public:
    Resolver(const OperatorMap& operatorsMap,
             const ProgramMap& programsMap,
             const VariableMap& variablesMap,
             const LiteralDefinitionPointer operatorLiteralDefinition) :
        operatorsMap(operatorsMap),
        programsMap(programsMap),
        variablesMap(variablesMap),
        operatorLiteralDefinition(operatorLiteralDefinition) { }

    LiteralVector resolve(LiteralVector tokens) const;

    const OperatorMap &getOperatorsMap() const {
        return operatorsMap;
    }
};


#endif //LO21_RESOLVER_H
