#include <gtest/gtest.h>
#include "../../repository/programs.h"
#include "../../literal/numeric.h"
#include "../../literal/operator.h"

TEST(ProgramsRepositoryTest, HashmapBehavior) {
    NumericLiteral intLiteral(4);
    OperatorLiteral plusLiteral("+");

    LiteralVector vector;
    vector.push_back(&intLiteral);
    vector.push_back(&plusLiteral);

    ProgramsRepository repository;

    ASSERT_FALSE(repository.has("FOO"));
    repository.set("FOO", vector);
    ASSERT_TRUE(repository.has("FOO"));
}

TEST(ProgramsRepositoryTest, IteratorBehavior) {
    NumericLiteral intLiteral(4);
    OperatorLiteral plusLiteral("+");

    LiteralVector vector;
    vector.push_back(&intLiteral);
    vector.push_back(&plusLiteral);

    ProgramsRepository repository;

    repository.set("FOO", vector);
    repository.set("BAR", vector);

    int count = 0;

    for (ProgramsRepository::iterator iterator = repository.begin(); iterator != repository.end(); ++iterator) {
        count++;
    }

    ASSERT_EQ(2, count);
}

TEST(ProgramsRepositoryTest, ThrowWhenNotFound) {
    NumericLiteral intLiteral(4);
    OperatorLiteral plusLiteral("+");

    LiteralVector vector;
    vector.push_back(&intLiteral);
    vector.push_back(&plusLiteral);

    ProgramsRepository repository;

    repository.set("FOO", vector);

    ASSERT_TRUE(repository.has("FOO"));
    ASSERT_FALSE(repository.has("BAR"));
    ASSERT_NO_THROW(repository.get("FOO"));
    ASSERT_ANY_THROW(repository.get("BAR"));
}
