#ifndef LO21_REPOSITORY_OBSERVABLE_H
#define LO21_REPOSITORY_OBSERVABLE_H


#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Repository;
class RepositoryObserver;

typedef shared_ptr<RepositoryObserver> RepositoryObserverPointer;
typedef shared_ptr<Repository> RepositoryPointer;

/*
 * Basis for the repositories implementing the Subject part of the
 * Observable design pattern
 *
 * Extended by the other repositories to notify listeners.
 */
class Repository {
private:
    vector<RepositoryObserverPointer> observers;

public:
    void attach(RepositoryObserver* observer) {
        observers.push_back(RepositoryObserverPointer(observer));
    }

    void notify();
};

/*
 * Basis for the objects observing repositories (observers).
 */
class RepositoryObserver {
public:
    virtual void update(Repository* repository) = 0;
};


#endif //LO21_REPOSITORY_OBSERVABLE_H
