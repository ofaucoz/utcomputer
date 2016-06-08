#ifndef LO21_EXCEPTION_UNDEFINED_ATOM_H
#define LO21_EXCEPTION_UNDEFINED_ATOM_H


#include <iostream>

using namespace std;

/**
 * Exception thrown when an atom can not be resolved to a known literal.
 */
struct UndefinedAtomException {
private:
    /**
     * The string representation of the atom that can not be resolved.
     */
    string value;

public:
    /**
     * @param value The string representation of the atom that can not be resolved.
     */
    UndefinedAtomException(const string &value) : value(value) { }

    /**
     * Get the string representation of the atom that can not be resolved.
     */
    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_UNDEFINED_ATOM_H
