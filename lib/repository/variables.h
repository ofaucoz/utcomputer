#ifndef LO21_REPOSITORY_VARIABLES_H
#define LO21_REPOSITORY_VARIABLES_H


#include "hashmap.h"
#include "../literal/numeric.h"

using namespace std;

/**
 * Repository storing the user variables.
 * This repository is a hash map.
 */
class VariablesRepository : public HashmapRepository<NumericLiteral> {};


#endif // LO21_REPOSITORY_VARIABLES_H
