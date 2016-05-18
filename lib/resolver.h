#ifndef LO21_RESOLVER_H
#define LO21_RESOLVER_H


#include <iostream>
#include "repository/operators.h"
#include "repository/programs.h"
#include "repository/variables.h"

using namespace std;

/*
 * The resolver uses the table of variables and the table of programs
 * to replace AtomLiterals by their equivalent numeric or operator literals.
 */
class Resolver {
private:
    OperatorsRepository operatorsRepository;
    ProgramsRepository programsRepository;
    VariablesRepository variablesRepository;

public:
    Resolver(const OperatorsRepository &operatorsRepository,
             const ProgramsRepository &programsRepository,
             const VariablesRepository &variablesRepository) :
        operatorsRepository(operatorsRepository),
        programsRepository(programsRepository),
        variablesRepository(variablesRepository) { }

    LiteralVector resolve(LiteralVector tokens) {
        return tokens;
    }
};


#endif //LO21_RESOLVER_H
