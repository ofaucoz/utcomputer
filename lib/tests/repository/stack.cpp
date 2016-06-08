#include <gtest/gtest.h>
#include "../../repository/stack.h"

class MockObserverException {
};

class MockObserver : public RepositoryObserver {
public:
    void update(Repository *repository) {
        throw MockObserverException();
    }
};

TEST(ObservableStackTest, Observer) {
    ObservableStack<int> stack;
    stack.attach(new MockObserver());

    EXPECT_EQ(0, stack.size());
    EXPECT_THROW(stack.pushAndNotify(4), MockObserverException);
    EXPECT_EQ(4, stack.top());
    EXPECT_EQ(1, stack.size());
    EXPECT_THROW(stack.popAndNotify(), MockObserverException);
    EXPECT_EQ(0, stack.size());
}
