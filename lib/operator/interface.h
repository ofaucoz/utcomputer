#ifndef LO21_OPERATOR_INTERFACE_H
#define LO21_OPERATOR_INTERFACE_H


#include <iostream>
#include <vector>
#include "../repository/literals.h"

using namespace std;

/*
 * Interface for all the operators.
 *
 * An operator is a class able to apply changes to the stack. It is associated to
 * a given token value that will be used to found it in the map by the runner.
 */
class OperatorInterface {
public:
    virtual string getTokenValue() const = 0;
    virtual void apply(LiteralsRepository& stack) const = 0;
};

typedef vector<OperatorInterface*> OperatorVector;

#endif // LO21_OPERATOR_INTERFACE_H
