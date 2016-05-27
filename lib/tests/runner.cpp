#include <gtest/gtest.h>
#include "../literal/interface.h"
#include "../literal/numeric.h"
#include "../literal/operator.h"
#include "../operator/interface.h"
#include "../operator/addition.h"
#include "../runner.h"

int countRunnerUpdates;

class MockRunnerObserver: public RepositoryObserver {
public:
    virtual void update() {
        countRunnerUpdates++;
    }
};

TEST(RunnerTest, Run) {
    OperatorMap operatorMap;
    operatorMap["+"] = OperatorPointer(new AdditionOperator);

    // Build input literals
    LiteralVector resolved;
    resolved.push_back(LiteralPointer(new NumericLiteral(3)));
    resolved.push_back(LiteralPointer(new NumericLiteral(4)));
    resolved.push_back(LiteralPointer(new OperatorLiteral("+")));

    // Stack
    LiteralsStack stack;
    stack.attach(new MockRunnerObserver);

    // Runner
    countRunnerUpdates = 0;

    Runner runner(operatorMap, stack);
    runner.run(resolved);

    EXPECT_EQ(3, countRunnerUpdates);
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("7", stack.top()->toString());
}

TEST(RunnerTest, RunMultiple) {
    OperatorMap operatorMap;
    operatorMap["+"] = OperatorPointer(new AdditionOperator);
    operatorMap["ADD"] = OperatorPointer(new AdditionOperator);

    // Build input literals
    LiteralVector resolved;
    resolved.push_back(LiteralPointer(new NumericLiteral(4)));
    resolved.push_back(LiteralPointer(new NumericLiteral(3)));
    resolved.push_back(LiteralPointer(new OperatorLiteral("+")));
    resolved.push_back(LiteralPointer(new NumericLiteral(7)));
    resolved.push_back(LiteralPointer(new OperatorLiteral("ADD")));

    // Stack
    LiteralsStack stack;
    stack.attach(new MockRunnerObserver);

    // Runner
    countRunnerUpdates = 0;

    Runner runner(operatorMap, stack);
    runner.run(resolved);

    EXPECT_EQ(5, countRunnerUpdates);
    EXPECT_EQ(1, stack.size());
    EXPECT_EQ("14", stack.top()->toString());
}
