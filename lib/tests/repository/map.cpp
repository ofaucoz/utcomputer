#include <gtest/gtest.h>
#include "../../repository/map.h"

class MockObserverException {};

class MockObserver: public RepositoryObserver {
public:
    void update(Repository* repository) {
        throw MockObserverException();
    }
};

TEST(ObservableMapTest, Observer) {
    ObservableMap<string, int> map;
    map.attach(new MockObserver());

    EXPECT_EQ(0, map.size());
    EXPECT_THROW(map.setAndNotify("FOO", 4), MockObserverException);
    EXPECT_TRUE(map.has("FOO"));
    EXPECT_EQ(4, map.get("FOO"));
    EXPECT_EQ(1, map.size());
    EXPECT_THROW(map.removeAndNotify("FOO"), MockObserverException);
    EXPECT_EQ(0, map.size());
}
