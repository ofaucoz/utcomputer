#ifndef LO21_LITERAL_INTERFACE_H
#define LO21_LITERAL_INTERFACE_H


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <memory>
#include "../repository/map.h"
#include "../repository/stack.h"

using namespace std;

/*
 * Interface for all the literals.
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
public:
    virtual const string toString() const = 0;

    virtual ~LiteralInterface() { };
};

/*
 * Literal pointer
 */
typedef shared_ptr<LiteralInterface> LiteralPointer;

/*
 * Literal vector
 */
typedef vector<LiteralPointer> LiteralVector;

/*
 * Literals stack
 */
typedef ObservableStack<LiteralPointer> LiteralsStack;

/*
 * Variables hashmap
 */
typedef ObservableMap<string, LiteralPointer> VariableMap;

/*
 * Programs hashmap
 */
typedef ObservableMap<string, LiteralVector> ProgramMap;


#endif // LO21_LITERAL_INTERFACE_H
