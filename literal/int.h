#ifndef LO21_LITERAL_INT_H
#define LO21_LITERAL_INT_H


#include "literal_interface.h"

struct IntLiteral : public NumericLiteralInterface {
private:
    int value;

public:
    IntLiteral(int value): value(value) {}

    int getValue() const {
        return value;
    }
};


#endif // LO21_LITERAL_INT_H
