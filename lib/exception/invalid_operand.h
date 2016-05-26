#ifndef LO21_EXCEPTION_INVALID_OPERAND_H
#define LO21_EXCEPTION_INVALID_OPERAND_H


#include <iostream>

using namespace std;

/*
 * Exception thrown when an operator received a literal it can't handle.
 */
struct InvalidOperandException {
private:
    string value;

public:
    InvalidOperandException(const string &value) : value(value) { }

    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_INVALID_OPERAND_H
