#ifndef LO21_NUMERIC_COMPLEX_IMAGINARY_H
#define LO21_NUMERIC_COMPLEX_IMAGINARY_H


#include "interface.h"

using namespace std;

class NumericComplexImaginary : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_NUMERIC_COMPLEX_IMAGINARY_H
