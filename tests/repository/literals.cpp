#include <gtest/gtest.h>
#include "../../repository/literals.h"
#include "../../literal/int.h"
#include "../../literal/expression.h"

TEST(LiteralsRepositoryTest, StackBehavior) {
    LiteralsRepository* repository = new LiteralsRepository();

    IntLiteral intLiteral(4);
    ExpressionLiteral expressionLiteral("expression");

    ASSERT_EQ(repository->count(), 0);
    repository->add(expressionLiteral);
    ASSERT_EQ(repository->count(), 1);
    repository->add(intLiteral);
    ASSERT_EQ(repository->count(), 2);
    ASSERT_EQ(repository->pop().toString(), intLiteral.toString());
    ASSERT_EQ(repository->count(), 1);
    ASSERT_EQ(repository->pop().toString(), expressionLiteral.toString());
    ASSERT_EQ(repository->count(), 0);
}
