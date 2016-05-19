#ifndef LO21_REPOSITORY_PROGRAMS_H
#define LO21_REPOSITORY_PROGRAMS_H


#include "hashmap.h"
#include "../literal/program.h"

using namespace std;

/**
 * Repository storing the user programs.
 * This repository is a hash map.
 */
class ProgramsRepository : public HashmapRepository<LiteralVector> {};


#endif // LO21_REPOSITORY_PROGRAMS_H
