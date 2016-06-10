#ifndef LO21_OPERATOR_NUMERIC_COMPLEX_REAL_H
#define LO21_OPERATOR_NUMERIC_COMPLEX_REAL_H


#include "interface.h"

using namespace std;

class NumericComplexRealOperator : public OperatorInterface {
public:
    /**
     * @inheritdoc
     */
    void apply(LiteralsStack &stack) const override;

    /**
     * @inheritdoc
     */
    int getPriority() const {
        return 0;
    }
};


#endif //LO21_OPERATOR_NUMERIC_COMPLEX_REAL_H
