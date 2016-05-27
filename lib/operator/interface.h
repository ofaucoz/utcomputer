#ifndef LO21_OPERATOR_INTERFACE_H
#define LO21_OPERATOR_INTERFACE_H


#include <iostream>
#include "../literal/interface.h"

using namespace std;

/*
 * Interface for all the operators.
 *
 * An operator is a class able to apply changes to the stack. It is associated to
 * a given token value that will be used to found it in the map by the runner.
 */
class OperatorInterface {
public:
    virtual void apply(LiteralsStack& stack) const = 0;
    virtual ~OperatorInterface() {};
};

/*
 * Operator pointer
 */
typedef shared_ptr<OperatorInterface> OperatorPointer;

/*
 * Operators hashmap
 */
typedef ObservableMap<string, OperatorPointer> OperatorMap;


#endif // LO21_OPERATOR_INTERFACE_H
