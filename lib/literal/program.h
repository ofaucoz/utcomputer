#ifndef LO21_LITERAL_PROGRAM_H
#define LO21_LITERAL_PROGRAM_H


#include "interface.h"

using namespace std;

/**
 * A program literal represents a string surrounded by brackets (a program).
 * For instance :
 *      [ DUP 0 < NEG ]
 */
struct ProgramLiteral : public LiteralInterface {
private:
    string program;

public:
    /**
     * @param program The program name.
     */
    ProgramLiteral(string program) : program(program) { }

    /**
     * @return The program name.
     */
    const string &getProgram() const {
        return program;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return program;
    };
};

typedef shared_ptr<ProgramLiteral> ProgramLiteralPointer;


#endif // LO21_LITERAL_PROGRAM_H
