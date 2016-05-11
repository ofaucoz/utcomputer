#ifndef LO21_LITERAL_REAL_H
#define LO21_LITERAL_REAL_H


#include "literal_interface.h"

/*
 * A real literal represent a real value.
 * For instance :
 *      -3.14
 */
struct RealLiteral : public NumericLiteralInterface {
private:
    double value;

public:
    RealLiteral(double value): value(value) {}

    double getValue() const {
        return value;
    }

    std::string toString() const {
        return std::to_string(value);
    };
};


#endif // LO21_LITERAL_REAL_H
