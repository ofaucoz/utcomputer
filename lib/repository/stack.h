#ifndef LO21_REPOSITORY_STACK_H
#define LO21_REPOSITORY_STACK_H


#include <stack>

using namespace std;

/*
 * Abstract repository template for stacks.
 */
template<typename Type> class StackRepository {
protected:
    stack<Type*> internalStack;

public:
    void add(Type& value) {
        internalStack.push(&value);
    }

    Type& pop() {
        Type* top = internalStack.top();
        internalStack.pop();

        return *top;
    }

    unsigned long count() const {
        return internalStack.size();
    }
};


#endif // LO21_REPOSITORY_STACK_H
