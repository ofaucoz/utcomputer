#ifndef LO21_LITERAL_COMPLEX_H
#define LO21_LITERAL_COMPLEX_H


#include "literal_interface.h"

/*
 * A complex literal represents a complex number composed of two numeric literals.
 * For instance :
 *      1.4$3/4
 */
struct ComplexLiteral : public LiteralInterface {
private:
    NumericLiteralInterface& real;
    NumericLiteralInterface& imaginary;

public:
    ComplexLiteral(NumericLiteralInterface& real, NumericLiteralInterface& imaginary): real(real), imaginary(imaginary) {}

    const NumericLiteralInterface &getReal() const {
        return real;
    }

    const NumericLiteralInterface &getImaginary() const {
        return imaginary;
    }
};


#endif // LO21_LITERAL_COMPLEX_H
