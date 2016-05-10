#ifndef LO21_REPOSITORY_ABSTRACT_H
#define LO21_REPOSITORY_ABSTRACT_H


#include <iostream>

/*
 * Interface for all the repositories.
 *
 * A repository is an object handling data objects (literals, variables, programs, ...),
 * letting the developer fetch and store them in an easy way.
 *
 * Repositories are able to dump their content as string to be saved in files.
 */
class RepositoryInterface {
    virtual std::string dumpToString() = 0;
    virtual void loadFromString(std::string dumpedString) = 0;
};


#endif // LO21_REPOSITORY_ABSTRACT_H
