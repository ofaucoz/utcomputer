#ifndef LO21_LEXER_H
#define LO21_LEXER_H


#include <iostream>
#include <vector>
#include <regex>
#include "literal/interface.h"
#include "literal_definition/interface.h"
#include "exception/invalid_syntax.h"

using namespace std;

/**
 * The Lexer is the first main component of the UTComputer library.
 *
 * The role of the Lexer is to transform a given string into a list of literals.
 * To do so, it uses a list of definitions (specialized factories for each literal
 * type). Using these definitions let the developer add it's own literals if he wants
 * to (and it let us, UTComputer developers, the possibility to add easily literals in
 * the future).
 */
class Lexer {
private:
    LiteralDefinitionVector definitions;

public:
    /**
     * Add a given definition pointer to the Lexer.
     *
     * @param definition A pointer to the definition to add.
     */
    void addDefinition(LiteralDefinitionInterface *definition) {
        definitions.push_back(LiteralDefinitionPointer(definition));
    }

    /**
     * Add a given definition to the Lexer.
     *
     * @param definition The definition to add.
     */
    void addDefinition(LiteralDefinitionPointer definition) {
        definitions.push_back(definition);
    }

    /**
     * Return the list of definitions currently registered in this Lexer.
     * Be careful that other definitions could be added after your code.
     *
     * @return The list of definitions registeredin this Lexer.
     */
    const LiteralDefinitionVector &getDefinitions() const {
        return definitions;
    }

    /**
     * This is the main method of the Lexer.
     *
     * Using the definitions, the Lexer build a vector of literals by
     * iterating until the command is empty. On each iteration, it tries
     * to match the beginning of the command with a definition. It it finds
     * a matching definition, it uses it to build a literal (as a factory)
     * and remove the matched string from the command. It it does not find
     * a matching definition, it throws an InvalidSyntaxException.
     *
     * @throws InvalidSyntaxException
     * @return The list of literals parsed from the given command.
     */
    LiteralVector tokenize(string command) const;
};


#endif // LO21_LEXER_H
