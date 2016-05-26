#include <gtest/gtest.h>
#include "../../repository/stack.h"

class MockObserverException {};

class MockObserver: public RepositoryObserver {
public:
    virtual void update() {
        throw MockObserverException();
    }
};

TEST(ObservableStackTest, Observer) {
    ObservableStack<int> stack;
    stack.attach(new MockObserver());

    ASSERT_EQ(0, stack.size());
    ASSERT_THROW(stack.pushAndNotify(4), MockObserverException);
    ASSERT_EQ(4, stack.top());
    ASSERT_EQ(1, stack.size());
    ASSERT_THROW(stack.popAndNotify(), MockObserverException);
    ASSERT_EQ(0, stack.size());
}
