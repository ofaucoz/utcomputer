#ifndef LO21_REPOSITORY_STACK_H
#define LO21_REPOSITORY_STACK_H


#include <stack>
#include "interface.h"

/*
 * Observable stack based on the standard stack and dispatching
 * notifications to observers on data change.
 */
template<class T> class ObservableStack : public std::vector<T>, public RepositoryObservable {
public:
    const T& top() const {
        return this->back();
    }

    void push(const T& item) {
        this->push_back(item);
    }

    void pushAndNotify(const T& item) {
        this->push(item);
        notify();
    }

    void pop() {
        this->pop_back();
    }

    void popAndNotify() {
        this->pop();
        notify();
    }
};


#endif //LO21_REPOSITORY_STACK_H
