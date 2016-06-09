#ifndef LO21_EXCEPTION_RUNTIME_H
#define LO21_EXCEPTION_RUNTIME_H


#include <iostream>

using namespace std;

/**
 * Exception thrown when a runtime error occurs (something that should not be possible
 * using the Graphical User Interface).
 */
struct RuntimeException {
private:
    /**
     * The description of the problem.
     */
    string description;

public:
    /**
     * @param description The description of the problem.
     */
    RuntimeException(const string &description) : description(description) { }

    /**
     * Get the description of the problem.
     */
    const string &getDescription() const {
        return description;
    }
};


#endif // LO21_EXCEPTION_RUNTIME_H
