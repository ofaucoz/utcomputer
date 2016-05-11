#ifndef LO21_REPOSITORY_LITERALS_H
#define LO21_REPOSITORY_LITERALS_H


#include <stack>
#include "repository_interface.h"
#include "../literal/literal_interface.h"

/**
 * Repository storing the literals.
 * This repository is a stack.
 */
class LiteralsRepository : public RepositoryInterface {
private:
    std::stack<LiteralInterface*> internalStack;

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

    std::string dumpToString() const {
        return "";
    }

    void loadFromString(std::string dumpedString) {

    }
};


#endif // LO21_REPOSITORY_LITERALS_H
