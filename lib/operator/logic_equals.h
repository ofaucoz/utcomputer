#ifndef LO21_LOGIC_EQUALS_H
#define LO21_LOGIC_EQUALS_H

#include "interface.h"

using namespace std;

class LogicEqualsOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_LOGIC_EQUALS_H
