#include "programs_map.h"

const string ProgramsMapSerializer::serialize(const ProgramMap map) const {
    json result;

    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    // For each program
    for (auto pIt = map.begin(); pIt != map.end(); ++pIt) {

        LiteralVector program = (*pIt).second;
        json jsonProgram;

        // For each literal, serialize it with the supporting definitions
        for (auto lIt = program.begin(); lIt != program.end(); ++lIt) {
            definitionFound = false;

            // We iterate over each literal definition trying to find one matching
            for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
                if ((*defIt)->support(*lIt)) {
                    jsonProgram.push_back((*defIt)->serialize(*lIt));
                    definitionFound = true;
                }
            }

            if (!definitionFound) {
                throw RuntimeException("Literal not supported by the Serializer");
            }
        }

        result[(*pIt).first] = jsonProgram;

    }

    return result.dump();
}

const ProgramMap ProgramsMapSerializer::unserialize(const string serialized) const {
    ProgramMap map;
    auto rawData = json::parse(serialized);

    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    for (json::iterator pIt = rawData.begin(); pIt != rawData.end(); ++pIt) {
        string programName = pIt.key();
        LiteralVector program;

        for (json::iterator lIt = pIt.value().begin(); lIt != pIt.value().end(); ++lIt) {
            definitionFound = false;
            string literalSerialized = lIt.value();

            // We iterate over each literal definition trying to find one matching
            for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
                if ((*defIt)->support(literalSerialized)) {
                    program.push_back((*defIt)->unserialize(literalSerialized));
                    definitionFound = true;
                }
            }

            if (!definitionFound) {
                throw RuntimeException("Serialized string not supported by the Serializer");
            }
        }

        map.set(programName, program);
    }

    return map;
}
