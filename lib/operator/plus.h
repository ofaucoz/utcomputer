#ifndef LO21_OPERATOR_PLUS_H
#define LO21_OPERATOR_PLUS_H


#include "interface.h"

using namespace std;

/*
 * Addition operator using the "+" symbol.
 */
class PlusOperator : public OperatorInterface {
public:
    const string getTokenValue() const override {
        return "+";
    }

    void apply(LiteralsStack& stack) const override {
        stack.size();
    }
};

#endif // LO21_OPERATOR_PLUS_H
