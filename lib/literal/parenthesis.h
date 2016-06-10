#ifndef LO21_LITERAL_PARENTHESIS_H
#define LO21_LITERAL_PARENTHESIS_H


#include "interface.h"

using namespace std;

/**
 * A parenthesis literal represents a parenthesis.
 * For instance :
 *      ( or )
 */
struct ParenthesisLiteral : public LiteralInterface {
private:
    string parenthesis;

public:
    /**
     * @param parenthesis The parenthesis ("(" or ")").
     */
    ParenthesisLiteral(string parenthesis) : parenthesis(parenthesis) { }

    /**
     * @return The parenthesis ("(" or ")").
     */
    const string &getParenthesis() const {
        return parenthesis;
    }

    /**
     * @inheritdoc
     */
    const string toString() const override {
        return parenthesis;
    };
};

typedef shared_ptr<ParenthesisLiteral> ParenthesisLiteralPointer;


#endif // LO21_LITERAL_PARENTHESIS_H
