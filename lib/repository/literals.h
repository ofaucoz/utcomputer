#ifndef LO21_REPOSITORY_LITERALS_H
#define LO21_REPOSITORY_LITERALS_H


#include "../literal/interface.h"
#include "stack.h"

/**
 * Stack of literals.
 */
class LiteralsRepository : public StackRepository<LiteralInterface> {};


#endif // LO21_REPOSITORY_LITERALS_H
