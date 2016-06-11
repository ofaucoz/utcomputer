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
class ProgramLiteralDefinition: public LiteralDefinitionInterface {
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

    /**
     * @inheritdoc
     */
    const bool support(LiteralPointer literal) const override {
        return dynamic_pointer_cast<ProgramLiteral>(literal) != nullptr;
    }

    /**
     * @inheritdoc
     */
    const bool support(string serialized) const {
        return serialized.substr(0, 8) == "program:";
    }

    /**
     * @inheritdoc
     */
    const string serialize(LiteralPointer literal) const {
        ProgramLiteralPointer programLiteral = dynamic_pointer_cast<ProgramLiteral>(literal);
        return "program:" + programLiteral->getProgram();
    }

    /**
     * @inheritdoc
     */
    LiteralPointer unserialize(string serialized) const {
        return createInstance(serialized.substr(8));
    }
};


#endif // LO21_LITERAL_DEFINITION_PROGRAM_H
