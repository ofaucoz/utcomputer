#ifndef LO21_REPOSITORY_MESSAGES_H
#define LO21_REPOSITORY_MESSAGES_H


#include <iostream>
#include <stack>
#include "../literal/interface.h"
#include "interface.h"

using namespace std;

/**
 * Stack of messages.
 */
class MessagesRepository : public RepositoryInterface {
protected:
    stack<string> internalStack;

public:
    void add(string value) {
        internalStack.push(value);
    }

    string pop() {
        string top = internalStack.top();
        internalStack.pop();

        return top;
    }

    unsigned long count() const {
        return internalStack.size();
    }
};


#endif // LO21_REPOSITORY_MESSAGES_H
