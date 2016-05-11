#include <gtest/gtest.h>
#include "../../repository/literals.h"
#include "../../literal/int.h"
#include "../../literal/expression.h"

TEST(LiteralsRepositoryTest, StackBehavior) {
    LiteralsRepository* repository = new LiteralsRepository();

    IntLiteral intLiteral(4);
    ExpressionLiteral expressionLiteral("expression");

    ASSERT_EQ(0, repository->count());
    repository->add(expressionLiteral);
    ASSERT_EQ(1, repository->count());
    repository->add(intLiteral);
    ASSERT_EQ(2, repository->count());
    ASSERT_EQ(intLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(1, repository->count());
    ASSERT_EQ(expressionLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(0, repository->count());
}
