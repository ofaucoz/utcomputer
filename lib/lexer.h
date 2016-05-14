#ifndef LO21_LEXER_H
#define LO21_LEXER_H


#include <iostream>
#include <vector>
#include <regex>
#include "literal/interface.h"
#include "literal_definition/interface.h"
#include "exception/invalid_syntax.h"

using namespace std;

/*
 * The lexer splits a given command into a list of literals using literal definitions
 * and pattern matching.
 */
class Lexer {
private:
    vector<LiteralDefinitionInterface*> definitions;

public:
    Lexer() {
        definitions = vector<LiteralDefinitionInterface*>();
    }

    ~Lexer() {
        vector<LiteralDefinitionInterface*>::iterator iterator;

        for (iterator = definitions.begin(); iterator != definitions.end(); ++iterator) {
            delete iterator.base();
        }
    }

    void addDefinition(LiteralDefinitionInterface& definition) {
        definitions.push_back(&definition);
    }

    vector<LiteralInterface*> tokenize(string command) {
        // Vector of found tokens
        vector<LiteralInterface*> tokens;

        // Initialization of variables
        vector<LiteralDefinitionInterface*>::iterator iterator;
        smatch matchs;
        string match;
        regex pattern;
        bool definitionFound;

        // While the command is not fully parsed
        while (command.size() > 0) {

            definitionFound = false;

            // We iterate over each literal definition trying to find one matching
            for (iterator = definitions.begin(); !definitionFound && iterator != definitions.end(); ++iterator) {
                // The pattern is defined by the LiteralDefinition object
                pattern = regex("^(" + (*iterator)->getPattern() + ")");

                // If we found the right literal definition, we build a literal using it
                if (regex_search(command, matchs, pattern)) {

                    match = matchs[1].str();

                    // We remove the matched element from the command
                    command = command.substr(match.length());

                    // We create a literal using the definition
                    tokens.push_back((*iterator)->createInstance(match));



                    // Stop the for here
                    definitionFound = true;
                }

            }

            if (!definitionFound) {
                // We found not literal definition matching the given string: invalid synthax
                throw new InvalidSyntaxException(command);
            }

        }

        return tokens;
    }
};


#endif // LO21_LEXER_H
