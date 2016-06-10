#ifndef LO21_LITERAL_INTERFACE_H
#define LO21_LITERAL_INTERFACE_H


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <memory>
#include "../repository/map.h"

using namespace std;

/**
 * Interface for all the literals.
 *
 * A literal is the simple representation of an element from a command to parse.
 * In the Parser-Lexer algorithm, literals are called tokens and they are created
 * by the Lexer to be analyzed by the parser. They store a type (here, it's the
 * class name) and a name to be used by the parser.
 *
 * Literals are structures as they only carry data.
 *
 * @see https://google.github.io/styleguide/cppguide.html#Structs_vs._Classes
 */
struct LiteralInterface {
public:
    /**
     * Virtual destructor to avoid conflict issues with children classes.
     */
    virtual ~LiteralInterface() { };

    /**
     * @return This literal string representation.
     */
    virtual const string toString() const = 0;
};

typedef shared_ptr<LiteralInterface> LiteralPointer;
typedef vector<LiteralPointer> LiteralVector;

/**
 * The variables hasmap is an association between a string
 * and a Literal (usually a numeric literal but it could be
 * theorically anything as anyone can add literals of their own).
 */
typedef ObservableMap<string, LiteralPointer> VariableMap;

/**
 * The programs hasmap is an association between a string
 * and a vector of Literals to execute in the Runner.
 * These programs will be resolved by the Resolver.
 */
typedef ObservableMap<string, LiteralVector> ProgramMap;


#endif // LO21_LITERAL_INTERFACE_H
