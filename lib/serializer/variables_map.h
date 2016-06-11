#ifndef LO21_SERIALIZER_VARIABLES_H
#define LO21_SERIALIZER_VARIABLES_H


#include <fstream>
#include "json.h"
#include "../literal_definition/interface.h"
#include "../exception/runtime.h"

using namespace std;
using json = nlohmann::json;

/**
 * The variables map serializer is able to transform a map of variables into a string
 * (to save it in a file) and to load a string as a map of variables (to load a previsouly
 * saved file).
 */
class VariablesMapSerializer {
private:
    LiteralDefinitionVector definitions;

public:
    /**
     * Add a given definition pointer to the Serializer.
     *
     * @param definition A pointer to the definition to add.
     */
    void addDefinition(LiteralDefinitionInterface *definition) {
        definitions.push_back(LiteralDefinitionPointer(definition));
    }

    /**
     * Add a given definition to the Serializer.
     *
     * @param definition The definition to add.
     */
    void addDefinition(LiteralDefinitionPointer definition) {
        definitions.push_back(definition);
    }

    /**
     * Create a string using the given map.
     *
     * @param map The map to serialize.
     * @return The serialized string.
     */
    const string serialize(const VariableMap map) const;

    /**
     * Create a map using the given serialized string.
     *
     * @param serialized The string to unserialize.
     * @return The unzerialized map.
     */
    const VariableMap unserialize(const string serialized) const;
};


#endif //LO21_SERIALIZER_VARIABLES_H
