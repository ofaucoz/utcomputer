#include "literals_stack.h"

const string LiteralsStackSerializer::serialize(LiteralsStack stack) const {
    json result;

    vector<std::shared_ptr<LiteralInterface>>::const_iterator iterator;
    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    // For each literal, serialize it with the supporting definitions
    for (iterator = stack.begin(); iterator != stack.end(); ++iterator) {
        definitionFound = false;

        // We iterate over each literal definition trying to find one matching
        for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
            if ((*defIt)->support(*iterator)) {
                result.push_back((*defIt)->serialize(*iterator));
                definitionFound = true;
            }
        }

        if (!definitionFound) {
            throw RuntimeException("Literal not supported by the Serializer");
        }
    }

    return result.dump();
}

const LiteralsStack LiteralsStackSerializer::unserialize(string serialized) const {
    LiteralsStack stack;
    auto rawData = json::parse(serialized);

    LiteralDefinitionVector::const_iterator defIt;
    bool definitionFound;

    for (json::iterator it = rawData.begin(); it != rawData.end(); ++it) {
        definitionFound = false;
        string literalSerialized = (*it);

        // We iterate over each literal definition trying to find one matching
        for (defIt = definitions.begin(); !definitionFound && defIt != definitions.end(); ++defIt) {
            if ((*defIt)->support(literalSerialized)) {
                stack.push((*defIt)->unserialize(literalSerialized));
                definitionFound = true;
            }
        }

        if (!definitionFound) {
            throw RuntimeException("Serialized string not supported by the Serializer");
        }
    }

    return stack;
}


