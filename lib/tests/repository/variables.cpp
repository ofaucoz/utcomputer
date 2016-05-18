#include <gtest/gtest.h>
#include "../../repository/variables.h"
#include "../../operator/plus.h"

TEST(VariablesRepositoryTest, HashmapBehavior) {
    NumericLiteral intLiteral(4);

    VariablesRepository repository;

    ASSERT_FALSE(repository.has("FOO"));

    repository.set("FOO", intLiteral);

    ASSERT_TRUE(repository.has("FOO"));
    ASSERT_EQ(intLiteral.toString(), repository.get("FOO").toString());
}

TEST(VariablesRepositoryTest, IteratorBehavior) {
    NumericLiteral intLiteral(4);

    VariablesRepository repository;

    repository.set("FOO", intLiteral);
    repository.set("BAR", intLiteral);

    int count = 0;

    for (VariablesRepository::Iterator iterator = repository.begin(); iterator != repository.end(); ++iterator) {
        count++;
        ASSERT_EQ(intLiteral.toString(), (*iterator).second->toString());
    }

    ASSERT_EQ(2, count);
}

TEST(VariablesRepositoryTest, ThrowWhenNotFound) {
    NumericLiteral intLiteral(4);

    VariablesRepository repository;

    repository.set("FOO", intLiteral);

    ASSERT_TRUE(repository.has("FOO"));
    ASSERT_FALSE(repository.has("BAR"));
    ASSERT_NO_THROW(repository.get("FOO"));
    ASSERT_ANY_THROW(repository.get("BAR"));
}
