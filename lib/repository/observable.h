#ifndef LO21_REPOSITORY_OBSERVABLE_H
#define LO21_REPOSITORY_OBSERVABLE_H


#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class RepositoryObserver;
typedef shared_ptr<RepositoryObserver> RepositoryObserverPointer;

/**
 * Repository are the "Observable" elements of the Observer pattern:
 * they can have observers (listeners) which will be notified when the
 * repository change.
 *
 * Usually, you will want to use implementations themselves, such as
 * ObservableMap or ObservableStack.
 */
class Repository {
private:
    /**
     * The vector of observers.
     */
    vector<RepositoryObserverPointer> observers;

public:
    /**
     * Attach a listener to be notified on data change in this repository.
     *
     * @param observer The observer to attach.
     */
    void attach(RepositoryObserver *observer) {
        observers.push_back(RepositoryObserverPointer(observer));
    }

    /**
     * Notify the observers that the data changed and they should update
     * themselves.
     */
    virtual void notify();
};

/**
 * RepositoryObserver are the "Observers" elements of the Observer pattern:
 * they are attached to repositories to be notified when they change.
 *
 * The user interface widgets are implementing this interface to re-render
 * on data change.
 */
class RepositoryObserver {
public:
    /**
     * This method will be called by the repositories which this observer is
     * attached to. This method is the place where observers should update
     * themselves according to the new data.
     *
     * @param repository The repository instance that notified this observer.
     */
    virtual void update(Repository *repository) = 0;
};


#endif //LO21_REPOSITORY_OBSERVABLE_H
