#ifndef LO21_SERIALIZER_STACK_H
#define LO21_SERIALIZER_STACK_H


#include <fstream>
#include "../literal/stack.h"
#include "../literal_definition/interface.h"
#include "json.h"

using namespace std;
using json = nlohmann::json;

/**
 * The literals stack serializer is able to transform a stack into a string
 * (to save it in a file) and to load a string as a stack (to load a previsouly
 * saved file).
 */
class LiteralsStackSerializer {
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
     * Create a string using the given stack.
     *
     * @param stack The stack to serialize.
     * @return The serialized string.
     */
    const string serialize(const LiteralsStack stack) const;

    /**
     * Create a stack using the given serialized string.
     *
     * @param serialized The string to unserialize.
     * @return The unzerialized stack.
     */
    const LiteralsStack unserialize(const string serialized) const;
};


#endif //LO21_SERIALIZER_STACK_H
