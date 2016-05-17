#include <gtest/gtest.h>
#include "../../repository/messages.h"

TEST(MessagesRepositoryTest, StackBehavior) {
    MessagesRepository repository;

    ASSERT_EQ(0, repository.count());

    repository.add("FOO");
    ASSERT_EQ(1, repository.count());

    repository.add("BAR");
    ASSERT_EQ(2, repository.count());

    ASSERT_EQ("BAR", repository.pop());
    ASSERT_EQ(1, repository.count());

    ASSERT_EQ("FOO", repository.pop());
    ASSERT_EQ(0, repository.count());
}
