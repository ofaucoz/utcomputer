#include <gtest/gtest.h>
#include "../../repository/literals.h"
#include "../../literal/atom.h"
#include "../../literal/complex.h"
#include "../../literal/expression.h"
#include "../../literal/int.h"
#include "../../literal/program.h"
#include "../../literal/rationnal.h"
#include "../../literal/real.h"

TEST(LiteralsRepositoryTest, StackBehavior) {
    LiteralsRepository* repository = new LiteralsRepository();

    AtomLiteral atomLiteral("FOO");
    IntLiteral intLiteral(4);
    RationnalLiteral rationnalLiteral(-3, 4);
    RealLiteral realLiteral(-3.14);
    ComplexLiteral complexLiteral(realLiteral, rationnalLiteral);
    ExpressionLiteral expressionLiteral("expression");
    ProgramLiteral programLiteral("[FOO 3 +]");

    ASSERT_EQ(0, repository->count());

    repository->add(atomLiteral);
    ASSERT_EQ(1, repository->count());

    repository->add(intLiteral);
    ASSERT_EQ(2, repository->count());

    repository->add(rationnalLiteral);
    ASSERT_EQ(3, repository->count());

    repository->add(realLiteral);
    ASSERT_EQ(4, repository->count());

    repository->add(complexLiteral);
    ASSERT_EQ(5, repository->count());

    repository->add(expressionLiteral);
    ASSERT_EQ(6, repository->count());

    repository->add(programLiteral);
    ASSERT_EQ(7, repository->count());

    ASSERT_EQ(programLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(6, repository->count());

    ASSERT_EQ(expressionLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(5, repository->count());

    ASSERT_EQ(complexLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(4, repository->count());

    ASSERT_EQ(realLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(3, repository->count());

    ASSERT_EQ(rationnalLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(2, repository->count());

    ASSERT_EQ(intLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(1, repository->count());

    ASSERT_EQ(atomLiteral.toString(), repository->pop().toString());
    ASSERT_EQ(0, repository->count());
}
