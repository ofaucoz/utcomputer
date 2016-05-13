#ifndef LO21_LITERAL_INTERFACE_H
#define LO21_LITERAL_INTERFACE_H


#include <iostream>

using namespace std;

/*
 * Interface for all the literal.
 *
 * A literal is the simple representation of an elmeent from a command to parse.
 * In the Parser-Lexer algorithm, literal are called tokens and they are created
 * by the lexer to be analyzed by the parser. They store a type (here, it's the
 * class name) and a name to be used by the parser.
 *
 * Literals are structures as they only carry data.
 * @see https://google.github.io/styleguide/cppguide.html#Structs_vs._Classes
 */
struct LiteralInterface {
    virtual string toString() const = 0;
};


#endif // LO21_LITERAL_INTERFACE_H
