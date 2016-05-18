#include <gtest/gtest.h>
#include "../../repository/operators.h"
#include "../../operator/plus.h"

TEST(OperatorsRepositoryTest, HashmapBehavior) {
    PlusOperator plusOperator;
    OperatorsRepository repository;

    ASSERT_FALSE(repository.has("+"));

    repository.set("+", plusOperator);

    ASSERT_TRUE(repository.has("+"));
    ASSERT_EQ(plusOperator.getTokenValue(), repository.get("+").getTokenValue());
}

TEST(OperatorsRepositoryTest, IteratorBehavior) {
    PlusOperator plusOperator;
    OperatorsRepository repository;

    repository.set("+", plusOperator);
    repository.set("PLUS", plusOperator);
    repository.set("ADD", plusOperator);

    int count = 0;

    for (OperatorsRepository::Iterator iterator = repository.begin(); iterator != repository.end(); ++iterator) {
        count++;
        ASSERT_EQ(plusOperator.getTokenValue(), (*iterator).second->getTokenValue());
    }
}

TEST(OperatorsRepositoryTest, ThrowWhenNotFound) {
    PlusOperator plusOperator;
    OperatorsRepository repository;

    repository.set("+", plusOperator);

    ASSERT_TRUE(repository.has("+"));
    ASSERT_FALSE(repository.has("-"));
    ASSERT_NO_THROW(repository.get("+"));
    ASSERT_ANY_THROW(repository.get("-"));
}
