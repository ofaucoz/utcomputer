#ifndef LO21_EXCEPTION_INVALID_OPERAND_H
#define LO21_EXCEPTION_INVALID_OPERAND_H


#include <iostream>

using namespace std;

/**
 * Exception thrown when an operator received a literal it can't handle.
 */
struct InvalidOperandException {
private:
    /**
     * The string representation of the literal that can't be handled.
     */
    string value;

public:
    /**
     * @param value The string representation of the literal that can't be handled;
     */
    InvalidOperandException(const string &value) : value(value) { }

    /**
     * Get the string representation of the literal that can't be handled.
     */
    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_INVALID_OPERAND_H
