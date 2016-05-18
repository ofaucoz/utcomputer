#ifndef LO21_EXCEPTION_UNDEFINED_ATOM_H
#define LO21_EXCEPTION_UNDEFINED_ATOM_H


#include <iostream>

using namespace std;

/*
 * Exception thrown when the syntax of the command is invalid.
 */
struct UndefinedAtomException {
private:
    string value;

public:
    UndefinedAtomException(const string &value) : value(value) { }

    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_UNDEFINED_ATOM_H
