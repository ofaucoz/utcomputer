#ifndef LO21_LOGIC_DIFFERENT_H
#define LO21_LOGIC_DIFFERENT_H


#include "interface.h"

using namespace std;

class LogicDifferentOperator : public OperatorInterface {
public:
    void apply(LiteralsStack& stack) const override;
};


#endif //LO21_LOGIC_DIFFERENT_H
