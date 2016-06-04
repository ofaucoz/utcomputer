//
// Created by orphee on 04/06/16.
//

#ifndef LO21_NUMERIC_COMPLEX_REAL_H
#define LO21_NUMERIC_COMPLEX_REAL_H


#include "interface.h"

using namespace std;

class NumericComplexReal : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_NUMERIC_COMPLEX_REAL_H
