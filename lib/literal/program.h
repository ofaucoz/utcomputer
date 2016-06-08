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
    string name;

public:
    /**
     * @param name The program name.
     */
    ProgramLiteral(string name) : name(name) { }

    /**
     * @return The program name.
     */
    const string &getName() const {
        return name;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return name;
    };
};

typedef shared_ptr<ProgramLiteral> ProgramLiteralPointer;


#endif // LO21_LITERAL_PROGRAM_H
