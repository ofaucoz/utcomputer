#ifndef LO21_RESOLVER_H
#define LO21_RESOLVER_H


#include <iostream>
#include "operator/interface.h"
#include "literal/operator.h"
#include "literal/numeric.h"
#include "literal_definition/interface.h"

using namespace std;

/**
 * The Resolver is the second main component of the UTComputer library.
 *
 * Called right after the Lexer, the role of the Resolver is to transform Atom literals
 * (which can't be used in a calculation of the Runner) into simpler literals (espacially
 * numeric ones.
 *
 * It uses the operators list, the programs list and the variables list to find what element
 * is an atom. When it finds what an atom is, it replaces this atom literal by its equivalent
 * (depending on what the atom is).
 */
class Resolver {
private:
    const OperatorMap &operatorsMap;
    const ProgramMap &programsMap;
    const VariableMap &variablesMap;
    const LiteralDefinitionPointer operatorLiteralDefinition;

public:
    /**
     * The Resolver needs the operators, the programs and the variables to work properly.
     * Moreover, while the OperatorLiteralDefinition matches native operators, custom ones
     * are treated as atoms. Therefore the Resolver also needs the factory for operator
     * literals in order to build operator literals using atom literals.
     *
     * @param operatorsMap The operators hashmap.
     * @param programsMap The programs hashmap.
     * @param variablesMap The variables hashmap.
     * @param operatorLiteralDefinition The operator literals definition/factory.
     */
    Resolver(const OperatorMap &operatorsMap,
             const ProgramMap &programsMap,
             const VariableMap &variablesMap,
             const LiteralDefinitionPointer operatorLiteralDefinition) :
        operatorsMap(operatorsMap),
        programsMap(programsMap),
        variablesMap(variablesMap),
        operatorLiteralDefinition(operatorLiteralDefinition) { }

    /**
     * Return the operators list (used by the eval operator to determine priorities of operators).
     *
     * @return The hashmap of operators of this Resolver.
     */
    const OperatorMap &getOperatorsMap() const {
        return operatorsMap;
    }

    /**
     * This is the main method of the Resolver.
     *
     * Using the hashmaps it has, the Resolver iterate over the given literals and every time
     * it encounter an Atom literal, it tries to transform it into:
     *      - an operator
     *      - a variable
     *      - a program
     *
     * If it fails (because the atom was not found in any hasmap), an UndefinedAtomException is thrown.
     *
     * This method also removes whitespaces literals as they have to be ignored.
     *
     * @throws UndefinedAtomException
     * @param tokens A list of literals (usually coming from the Lexer).
     * @return A simpler list of literals without atom literals.
     */
    LiteralVector resolve(LiteralVector tokens) const;
};


#endif //LO21_RESOLVER_H
