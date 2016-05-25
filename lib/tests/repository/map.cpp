#include <gtest/gtest.h>
#include "../../repository/map.h"

class MockObserverException {};

class MockObserver: public RepositoryObserver {
public:
    virtual void update() {
        throw MockObserverException();
    }
};

TEST(ObservableMapTest, Observer) {
    ObservableMap<string, int> map;
    map.attach(new MockObserver());

    ASSERT_THROW(map.setAndNotify("FOO", 4), MockObserverException);
    ASSERT_THROW(map.removeAndNotify("FOO"), MockObserverException);
}
