#ifndef LO21_REPOSITORY_LITERALS_H
#define LO21_REPOSITORY_LITERALS_H


#include <stack>
#include "interface.h"
#include "../literal/interface.h"

using namespace std;

/**
 * Repository storing the literals.
 * This repository is a stack.
 */
class LiteralsRepository : public RepositoryInterface {
private:
    stack<LiteralInterface*> internalStack;

public:
    void add(LiteralInterface& literal) {
        internalStack.push(&literal);
    }

    LiteralInterface& pop() {
        LiteralInterface* top = internalStack.top();
        internalStack.pop();

        return *top;
    }

    unsigned long count() const {
        return internalStack.size();
    }

    string dumpToString() const {
        return "";
    }

    void loadFromString(string dumpedString) {

    }
};


#endif // LO21_REPOSITORY_LITERALS_H
