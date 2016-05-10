#ifndef LO21_LITERAL_REAL_H
#define LO21_LITERAL_REAL_H


#include "literal_interface.h"

struct RealLiteral : public NumericLiteralInterface {
private:
    double value;

public:
    RealLiteral(double value): value(value) {}

    double getValue() const {
        return value;
    }
};


#endif // LO21_LITERAL_REAL_H
