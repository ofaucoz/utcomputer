#ifndef LO21_OPERATOR_PLUS_H
#define LO21_OPERATOR_PLUS_H


#include "interface.h"

using namespace std;

/*
 * Addition operator using the "+" symbol.
 */
class PlusOperator : public OperatorInterface {
public:
    string getTokenValue() const {
        return "+";
    }

    void apply(LiteralsRepository& stack) const {
        stack.count();
    }
};

#endif // LO21_OPERATOR_PLUS_H
