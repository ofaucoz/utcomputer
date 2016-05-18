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
    ProgramLiteral(string value): value(value) {}

    const string &getValue() const {
        return value;
    }

    string toString() const {
        return value;
    };
};


#endif // LO21_LITERAL_PROGRAM_H
