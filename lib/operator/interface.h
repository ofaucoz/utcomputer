#ifndef LO21_OPERATOR_INTERFACE_H
#define LO21_OPERATOR_INTERFACE_H


#include <iostream>
#include "../literal/interface.h"

using namespace std;

/**
 * Interface for all the operators.
 *
 * An operator is a class able to apply changes to the stack. It is associated to
 * a given token value that will be used to found it in the map by the Runner.
 */
class OperatorInterface {
public:
    /**
     * Apply the operation to the given stack. The stack is given
     * by reference to be modified without returned value.
     *
     * @param stack The stack to modify according to the operation.
     */
    virtual void apply(LiteralsStack &stack) const = 0;

    /**
     * Return the priority of this operator.
     * Default priority is 0 but some operators need a higher one (such as
     * multiplication or division that have a priority of 10).
     * This priority is used during the EVAL execution of an expression.
     *
     * @return The operator priority as an integer.
     */
    virtual int getPriority() const = 0;

    /**
     * Virtual destructor to avoid conflict issues with children classes.
     */
    virtual ~OperatorInterface() { };
};

typedef shared_ptr<OperatorInterface> OperatorPointer;

/*
 * Operators hashmap used by the Resolver and the Runner to access operators.
 */
typedef ObservableMap<string, OperatorPointer> OperatorMap;


#endif // LO21_OPERATOR_INTERFACE_H
