#ifndef LO21_EXCEPTION_UNSUPPORTED_LITERAL_H
#define LO21_EXCEPTION_UNSUPPORTED_LITERAL_H


#include <iostream>

using namespace std;

/**
 * Exception thrown when the Runner encounter an unsupported literal.
 */
struct UnsupportedLiteralException {
private:
    /**
     * The string representation of the unsupported literal.
     */
    string value;

public:
    /**
     * @param value The string representation of the unsupported literal.
     */
    UnsupportedLiteralException(const string &value) : value(value) { }

    /**
     * Get the string representation of the unsupported literal.
     */
    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_UNSUPPORTED_LITERAL_H_ATOM_H
