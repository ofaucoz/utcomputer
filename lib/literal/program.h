#ifndef LO21_LITERAL_PROGRAM_H
#define LO21_LITERAL_PROGRAM_H


#include "interface.h"

using namespace std;

/*
 * A program literal represents a string surrounded by brackets.
 * For instance :
 *      [ DUP 0 < NEG ]
 */
struct ProgramLiteral : public LiteralInterface {
private:
    string value;

public:
    ProgramLiteral(string value) : value(value) { }

    const string &getValue() const {
        return value;
    }

    const string toString() const override {
        return value;
    };
};

/*
 * Program literal pointer
 */
typedef shared_ptr<ProgramLiteral> ProgramLiteralPointer;


#endif // LO21_LITERAL_PROGRAM_H
