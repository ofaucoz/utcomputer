#ifndef LO21_EXCEPTION_UNSUPPORTED_LITERAL_H
#define LO21_EXCEPTION_UNSUPPORTED_LITERAL_H


#include <iostream>

using namespace std;

/*
 * Exception thrown when the runner encounter an unsupported literal
 * (resolver inserted unsupported literal).
 */
struct UnsupportedLiteralException {
private:
    string value;

public:
    UnsupportedLiteralException(const string &value) : value(value) { }

    const string &getValue() const {
        return value;
    }
};


#endif // LO21_EXCEPTION_UNSUPPORTED_LITERAL_H_ATOM_H
