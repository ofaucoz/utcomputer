#include <stack>
#include "eval.h"

void EvalOperator::apply(LiteralsStack &stack) const {
    if (stack.size() < 1) {
        throw InvalidSyntaxException("Eval operator requires 1 operand");
    }

    LiteralPointer first = stack.top();
    stack.pop();

    ExpressionLiteralPointer firstEpression = dynamic_pointer_cast<ExpressionLiteral>(first);
    ProgramLiteralPointer firstProgram = dynamic_pointer_cast<ProgramLiteral>(first);

    if (!firstEpression&&!firstProgram) {
        throw InvalidOperandException(first->toString());
    }

    // Ignore first and last characters (expression quotes or [] for program) and postfix if it's an expression
    if(!firstProgram) {
        computer.execute(postfix(firstEpression->getValue().substr(1, firstEpression->getValue().size() - 2)));
    } else if(!firstEpression){
        computer.execute(firstProgram->toString().substr(1, firstProgram->toString().size() - 2));
    }
}

int EvalOperator::findPriority(string name) const {
    OperatorMap operatorMap = computer.getResolver().getOperatorsMap();

    if (operatorMap.has(name)) {
        return operatorMap.get(name)->getPriority();
    }

    return 0;
}

LiteralVector EvalOperator::postfix(string infix) const {

    /*
     * Ignore whitespaces
     */
    infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end());

    /*
     * Tokenize
     */
    Lexer lexer = computer.getLexer();
    lexer.addDefinition(new ParenthesisLiteralDefinition());
    lexer.addDefinition(new CommaLiteralDefinition());

    LiteralVector tokens = lexer.tokenize(infix);

    /*
     * Postfix
     *
     * This algorithm uses two stacks: one for infixed operators (native ones) and another for
     * previxed operators (custom ones).
     *
     * It also keeps track of the last token to determine if a parenthesis is an operator call or
     * a priority indicator.
     */
    LiteralVector postfixed;
    stack<LiteralPointer> prefixOperatorsStack;
    stack<LiteralPointer> stack;
    LiteralPointer previous;

    for (LiteralVector::iterator token = tokens.begin(); token != tokens.end(); ++token) {

        // Parenthesis
        if (ParenthesisLiteralPointer parenthesisLiteral = dynamic_pointer_cast<ParenthesisLiteral>(*token)) {

            // Parenthesis can be either an indication of priority or a custom operator
            if (parenthesisLiteral->getParenthesis() == "(") {

                // If the previous token was an atom, we are in the case of an operator
                if (previous != nullptr) {
                    AtomLiteralPointer previousAtom = dynamic_pointer_cast<AtomLiteral>(previous);

                    if (previousAtom) {
                        // We remove the last token from the result (we will readd it after its operands)
                        // and add it in a special stack
                        postfixed.pop_back();
                        prefixOperatorsStack.push(previousAtom);
                    } else {
                        // It's a classical parenthesis: we push nullptr to count the opening parenthesis
                        // and know where we are in the closing parenthesis case
                        prefixOperatorsStack.push(nullptr);
                    }
                }

                // We always push the parenthesis as an operator
                stack.push(*token);

            } else {

                // Closing parenthesis: we resolve the stack
                while (!stack.empty() && stack.top()->toString() != "(") {
                    postfixed.push_back(stack.top());
                    stack.pop();
                }

                // And then, if there was a custom operator for this closing parenthesis, we add it
                if (!prefixOperatorsStack.empty()) {
                    if (prefixOperatorsStack.top() != nullptr) {
                        postfixed.push_back(prefixOperatorsStack.top());
                    }

                    prefixOperatorsStack.pop();
                }

                // Remove the associated opening parenthesis from the stack
                stack.pop();

            }

            // Native operator (+ - * /)
        } else if (OperatorLiteralPointer operatorLiteral = dynamic_pointer_cast<OperatorLiteral>(*token)) {

            // Find the priority and push to the stack accordingly
            int currentPriority = findPriority(operatorLiteral->toString());

            while (!stack.empty() && currentPriority < findPriority(stack.top()->toString())) {
                postfixed.push_back(stack.top());
                stack.pop();
            }

            stack.push(operatorLiteral);

            // Comma
        } else if (dynamic_pointer_cast<CommaLiteral>(*token)) {

            // A comma acts as a closing parenthesis and an opnening one right after
            while (!stack.empty() && stack.top()->toString() != "(") {
                postfixed.push_back(stack.top());
                stack.pop();
            }

            stack.pop();

            stack.push(LiteralPointer(new ParenthesisLiteral("(")));

            // Other tokens (numerics, expressions, ...)
        } else {
            // Simply push them
            postfixed.push_back(*token);
        }

        // Keep track of the previous tokens
        previous = *token;
    }

    // Pop any remaining operators from the stack and push them
    while (!stack.empty()) {
        postfixed.push_back(stack.top());
        stack.pop();
    }

    return postfixed;
}
