#ifndef LO21_REPOSITORY_STACK_H
#define LO21_REPOSITORY_STACK_H


#include <stack>
#include "observable.h"

/**
 * An observable stack is a standard stack with the addition of being a repository,
 * and therefore being observable. It dispatches notifications to listeners
 * when the data change.
 *
 * In reality, while this class interacts as a standard stack (by implementing the same
 * methods as the standard stack), it is actually a vector. Using a vector let us
 * iterate over the elements with ease.
 */
template<class T>
class ObservableStack : public std::vector<T>, public Repository {
public:

    /**
     * Read the item on top of the stack.
     *
     * @return The item on top of the stack.
     */
    const T &top() const {
        return this->back();
    }

    /**
     * Push an element on top of the stack.
     *
     * @param item The item to push.
     */
    void push(const T &item) {
        this->push_back(item);
    }

    /**
     * Act as `push` (push an element on top of the stack) and notify the changement right after.
     *
     * @param item The item to push.
     */
    void pushAndNotify(const T &item) {
        this->push(item);
        notify();
    }

    /**
     * Remove the top element from the stack.
     */
    void pop() {
        this->pop_back();
    }

    /**
     * Act as `pop` (remove the top element from the stack) and notify the changement right after.
     */
    void popAndNotify() {
        this->pop();
        notify();
    }

};


#endif //LO21_REPOSITORY_STACK_H
