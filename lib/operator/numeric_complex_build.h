#ifndef LO21_NUMERIC_COMPLEX_BUILD_H
#define LO21_NUMERIC_COMPLEX_BUILD_H


#include "interface.h"
#include "../exception/invalid_syntax.h"
#include "../literal/numeric.h"
#include "../exception/invalid_operand.h"

using namespace std;

class NumericComplexBuildOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};



#endif //LO21_NUMERIC_COMPLEX_BUILD_H
