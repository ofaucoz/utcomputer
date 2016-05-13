#ifndef LO21_EXCEPTION_INVALID_SYNTAX_H
#define LO21_EXCEPTION_INVALID_SYNTAX_H


#include <iostream>

using namespace std;

/*
 * Exception thrown when the syntax of the command is invalid.
 */
struct InvalidSyntaxException {
private:
    string value;

public:
    InvalidSyntaxException(const string &value) : value(value) { }
};


#endif // LO21_EXCEPTION_INVALID_SYNTAX_H
