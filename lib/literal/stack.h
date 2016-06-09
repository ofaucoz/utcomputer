#ifndef LO21_LITERAL_STACK_H
#define LO21_LITERAL_STACK_H


#include "interface.h"
#include "../exception/runtime.h"

using namespace std;

typedef vector<LiteralPointer> LiteralsStackState;

/**
 * Stack of literals.
 *
 * This class implements the Observable part of the Observer design
 * pattern. It also implements an internal Memento to provides undo/redo
 * features.
 *
 * This class is used by the Runner for execution.
 */
class LiteralsStack : public Repository {
private:
    unordered_map<int, LiteralsStackState> savedStates;
    LiteralsStackState currentState;
    int currentStateIndex;

public:
    /**
     * Initialize the stack with a first state.
     */
    LiteralsStack() {
        currentState = LiteralsStackState();
        currentStateIndex = -1;
        save();
    }

    /**
     * Return the size of the current stack.
     *
     * @return The size of the current stack.
     */
    virtual const unsigned long size() const {
        return currentState.size();
    }

    /**
     * Read the item on top of the current stack.
     *
     * @return The item on top of the current stack.
     */
    virtual const LiteralPointer &top() const {
        return currentState.back();
    }

    /**
     * Read the second item on top of the current stack.
     *
     * @return The second item on top of the current stack.
     */
    virtual const LiteralPointer &second() const {
        return currentState.at(currentState.size() - 2);
    }

    /**
     * Read the item on top of the current stack.
     *
     * @return The item on top of the current stack.
     */
    virtual vector<std::shared_ptr<LiteralInterface>>::const_iterator begin() const {
        return currentState.begin();
    }

    /**
     * Read the item on top of the current stack.
     *
     * @return The item on top of the current stack.
     */
    virtual vector<std::shared_ptr<LiteralInterface>>::const_iterator end() const {
        return currentState.end();
    }

    /**
     * Push an element on top of the current stack.
     *
     * @param item The item to push.
     */
    virtual void push(const LiteralPointer &item) {
        currentState.push_back(item);
    }

    /**
     * Act as `push` (push an element on top of the current stack) and notify the changement right after.
     *
     * @param item The item to push.
     */
    virtual void pushAndNotify(const LiteralPointer &item) {
        this->push(item);
        notify();
    }

    /**
     * Remove the top element from the current stack.
     */
    virtual void pop() {
        currentState.pop_back();
    }

    /**
     * Act as `pop` (remove the top element from the current stack) and notify the changement right after.
     */
    virtual void popAndNotify() {
        this->pop();
        notify();
    }

    /**
     * Save the current state in the stack states.
     */
    virtual void save() {
        currentStateIndex++;
        this->savedStates.emplace(currentStateIndex, currentState);
    }

    /**
     * Return to the previous state.
     *
     * @throws RuntimeException When this stack has no more previous state.
     */
    virtual void undo() {
        if (currentStateIndex == 0) {
            throw RuntimeException("This stack has no more previous state.");
        }

        currentStateIndex--;
        currentState = this->savedStates.at(currentStateIndex);
    }

    /**
     * Go forward to the next state.
     *
     * @throws RuntimeException When this stack is already at its last state.
     */
    virtual void redo() {
        if (currentStateIndex == this->savedStates.size() - 1) {
            throw RuntimeException("This stack is already at its last state.");
        }

        currentStateIndex++;
        currentState = this->savedStates.at(currentStateIndex);
    }
};


#endif // LO21_LITERAL_STACK_H
