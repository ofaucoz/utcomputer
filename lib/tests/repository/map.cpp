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

    ASSERT_EQ(0, map.size());
    ASSERT_THROW(map.setAndNotify("FOO", 4), MockObserverException);
    ASSERT_TRUE(map.has("FOO"));
    ASSERT_EQ(4, map.get("FOO"));
    ASSERT_EQ(1, map.size());
    ASSERT_THROW(map.removeAndNotify("FOO"), MockObserverException);
    ASSERT_EQ(0, map.size());
}
