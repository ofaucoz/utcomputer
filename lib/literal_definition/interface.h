#ifndef LO21_LITERAL_DEFINITION_INTERFACE_H
#define LO21_LITERAL_DEFINITION_INTERFACE_H


#include <iostream>
#include <regex>
#include "../literal/interface.h"

using namespace std;

/**
 * Interface for all literal definitions.
 *
 * A literal definition is a factory for a specific type of literal. The
 * Lexer will use these definitions to create the literals from the command string.
 *
 * This definitions system let the developer add custom literals to the Lexer.
 */
class LiteralDefinitionInterface {
public:
    /**
     * Return the pattern associated to this definition.
     * This pattern is the regex used to match a string to a this definition
     * (this matched string will then be provided to `createInstance`).
     *
     * @return The regex pattern to use to match the command in the Lexer.
     */
    virtual const string getPattern() const = 0;

    /**
     * Using the previously matched string, this method create an instance
     * of the literal it handles and return it.
     *
     * @param value The matched value from the Lexer.
     * @return The literal built using the given value.
     */
    virtual LiteralPointer createInstance(string value) const = 0;

    /**
     * Virtual destructor to avoid conflict issues with children classes.
     */
    virtual ~LiteralDefinitionInterface() { };
};

typedef shared_ptr<LiteralDefinitionInterface> LiteralDefinitionPointer;
typedef vector<LiteralDefinitionPointer> LiteralDefinitionVector;


#endif // LO21_LITERAL_DEFINITION_INTERFACE_H
