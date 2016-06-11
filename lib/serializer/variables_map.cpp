#include "variables_map.h"

const string VariablesMapSerializer::serialize(const VariableMap map) const {
    json result;

    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    // For each variable
    for (auto vIt = map.begin(); vIt != map.end(); ++vIt) {
        LiteralPointer literal = (*vIt).second;
        definitionFound = false;

        // We iterate over each literal definition trying to find one matching
        for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
            if ((*defIt)->support(literal)) {
                result[(*vIt).first] = (*defIt)->serialize(literal);
                definitionFound = true;
            }
        }

        if (!definitionFound) {
            throw RuntimeException("Literal not supported by the Serializer");
        }
    }

    return result.dump();
}

const VariableMap VariablesMapSerializer::unserialize(const string serialized) const {
    VariableMap map;
    auto rawData = json::parse(serialized);

    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    for (json::iterator vIt = rawData.begin(); vIt != rawData.end(); ++vIt) {
        definitionFound = false;
        string variableName = vIt.key();
        string literalSerialized = vIt.value();

        // We iterate over each literal definition trying to find one matching
        for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
            if ((*defIt)->support(literalSerialized)) {
                map.set(variableName, (*defIt)->unserialize(literalSerialized));
                definitionFound = true;
            }
        }

        if (!definitionFound) {
            throw RuntimeException("Serialized string not supported by the Serializer");
        }
    }

    return map;
}
