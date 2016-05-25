#include "observable.h"

void Repository::notify() const {
    for (vector<RepositoryObserverPointer>::const_iterator it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update();
    }
}
