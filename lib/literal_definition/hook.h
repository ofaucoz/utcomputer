#ifndef LO21_LITERAL_DEFINITION_HOOK_H
#define LO21_LITERAL_DEFINITION_HOOK_H


#include <iostream>
#include <regex>
#include "interface.h"
#include "../literal/hook.h"
#include "../exception/invalid_operand.h"
#include "../exception/invalid_syntax.h"

using namespace std;

/**
 * Definition of a hook literal.
 */
class HookLiteralDefinition : public LiteralDefinitionInterface {
public:
    /**
     * @inheritdoc
     */
    const string getPattern() const override {
        return "\\[|\\]";
    }

    /**
     * @inheritdoc
     */
    LiteralPointer createInstance(string value) const override {
        return LiteralPointer(new HookLiteral(value));
    }
};


#endif // LO21_LITERAL_DEFINITION_HOOK_H
