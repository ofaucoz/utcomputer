#ifndef LO21_SERIALIZER_PROGRAMS_H
#define LO21_SERIALIZER_PROGRAMS_H


#include <fstream>
#include "json.h"
#include "../literal_definition/program.h"
#include "../exception/runtime.h"

using namespace std;
using json = nlohmann::json;

/**
 * The programs map serializer is able to transform a map of programs into a string
 * (to save it in a file) and to load a string as a map of programs (to load a previsouly
 * saved file).
 */
class ProgramsMapSerializer {
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
    const string serialize(const ProgramMap map) const;

    /**
     * Create a map using the given serialized string.
     *
     * @param serialized The string to unserialize.
     * @return The unzerialized map.
     */
    const ProgramMap unserialize(const string serialized) const;
};


#endif //LO21_SERIALIZER_PROGRAMS_H
