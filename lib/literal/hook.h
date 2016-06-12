#ifndef LO21_LITERAL_HOOK_H
#define LO21_LITERAL_HOOK_H


#include "interface.h"

using namespace std;

/**
 * A Hook literal represents a hook.
 * For instance :
 *      [ or ]
 */
struct HookLiteral : public LiteralInterface {
private:
    string hook;

public:
    /**
     * @param HOOK The HOOK ["[" or "]"].
     */
    HookLiteral(string hook) : hook(hook) { }

    /**
     * @return The HOOK ["[" or "]"].
     */
    const string &getHook() const {
        return hook;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return hook;
    };
};

typedef shared_ptr<HookLiteral> HookLiteralPointer;


#endif // LO21_LITERAL_WHITESPACE_H
