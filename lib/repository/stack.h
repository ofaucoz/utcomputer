#ifndef LO21_REPOSITORY_STACK_H
#define LO21_REPOSITORY_STACK_H


#include <stack>
#include "observable.h"

/*
 * Observable stack based on the standard stack and dispatching
 * notifications to observers on data change.
 */
template<class T> class ObservableStack : public std::stack<T>, public Repository {
public:
    void pushAndNotify(const T& item) {
        this->push(item);
        notify();
    }

    void popAndNotify() {
        this->pop();
        notify();
    }
};


#endif //LO21_REPOSITORY_STACK_H
