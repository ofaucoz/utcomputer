#ifndef LO21_LITERAL_INTERFACE_H
#define LO21_LITERAL_INTERFACE_H


#include <iostream>

/*
 * Interface for all the literal.
 *
 * A literal is the simple representation of an elmeent from a command to parse.
 * In the Parser-Lexer algorithm, literal are called tokens and they are created
 * by the lexer to be analyzed by the parser. They store a type (here, it's the
 * class name) and a value to be used by the parser.
 *
 * LITERAL are structures as they only carry data.
 * @see https://google.github.io/styleguide/cppguide.html#Structs_vs._Classes
 */
struct LiteralInterface {
    virtual std::string toString() = 0;
};

/*
 * Interface for the numeric literal.
 *
 * Used by the parser to dinstinguish numeric literal from other ones.
 */
struct NumericLiteralInterface : public LiteralInterface {};


#endif // LO21_LITERAL_INTERFACE_H
