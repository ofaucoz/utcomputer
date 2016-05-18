#include "resolver.h"
#include "literal/atom.h"

LiteralVector Resolver::resolve(LiteralVector tokens) {
    LiteralVector resolved;

    // For each atom token, replace it by its resolved components from the repositories
    for (LiteralVector::iterator iterator = tokens.begin(); iterator != tokens.end(); ++iterator) {
        if (AtomLiteral* atom = dynamic_cast<AtomLiteral*>(*iterator)) {

            if (operatorsRepository.has(atom->getValue())) {
                // This atom is an operator
                resolved.push_back(operatorLiteralDefinition.createInstance(atom->getValue()));
            } else if (variablesRepository.has(atom->getValue())) {
                // This atom is a variable
                resolved.push_back(&variablesRepository.get(atom->getValue()));
            } else if (programsRepository.has(atom->getValue())) {
                // This atom is a program
                LiteralVector program = programsRepository.get(atom->getValue());

                for (LiteralVector::iterator programIt = program.begin(); programIt != program.end(); ++programIt) {
                    resolved.push_back(*programIt);
                }
            }

        } else {
            resolved.push_back(*iterator);
        }
    }

    return resolved;
}