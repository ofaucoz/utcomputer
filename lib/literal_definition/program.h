#ifndef LO21_LITERAL_DEFINITION_PROGRAM_H
#define LO21_LITERAL_DEFINITION_PROGRAM_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/program.h"

using namespace std;

/**
 * Definition of a program literal.
 */
class ProgramLiteralDefinition : public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\\[[^\\]]*\\]";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new ProgramLiteral(value));
    }
};


#endif // LO21_LITERAL_DEFINITION_PROGRAM_H
