#ifndef LO21_EXCEPTION_INVALID_SYNTAX_H
#define LO21_EXCEPTION_INVALID_SYNTAX_H


#include <iostream>

using namespace std;

/**
 * Exception thrown when the syntax of the command is invalid.
 */
struct InvalidSyntaxException {
private:
    /**
     * The string representation of the literal with an invalid syntax.
     */
    string value;

public:
    /**
     * @param value The string representation of the literal with an invalid syntax.
     */
    InvalidSyntaxException(const string &value) : value(value) { }

    /**
     * Get the string representation of the literal with an invalid syntax.
     */
    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_INVALID_SYNTAX_H
