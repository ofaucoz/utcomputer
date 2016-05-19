#include <gtest/gtest.h>
#include "../../repository/literals.h"
#include "../../literal/atom.h"
#include "../../literal/numeric.h"
#include "../../literal/expression.h"
#include "../../literal/program.h"

TEST(LiteralsRepositoryTest, StackBehavior) {
    LiteralsRepository repository;

    AtomLiteral atomLiteral("FOO");
    NumericLiteral complexLiteral(-3.14, 2, 4, 1);
    ExpressionLiteral expressionLiteral("expression");
    ProgramLiteral programLiteral("[FOO 3 +]");

    ASSERT_EQ(0, repository.count());

    repository.add(atomLiteral);
    ASSERT_EQ(1, repository.count());

    repository.add(complexLiteral);
    ASSERT_EQ(2, repository.count());

    repository.add(expressionLiteral);
    ASSERT_EQ(3, repository.count());

    repository.add(programLiteral);
    ASSERT_EQ(4, repository.count());

    ASSERT_EQ(programLiteral.toString(), repository.pop().toString());
    ASSERT_EQ(3, repository.count());

    ASSERT_EQ(expressionLiteral.toString(), repository.pop().toString());
    ASSERT_EQ(2, repository.count());

    ASSERT_EQ(complexLiteral.toString(), repository.pop().toString());
    ASSERT_EQ(1, repository.count());

    ASSERT_EQ(atomLiteral.toString(), repository.pop().toString());
    ASSERT_EQ(0, repository.count());
}
