#include <gtest/gtest.h>
#include "../../literal/stack.h"
#include "../../literal/whitespace.h"
#include "../../literal/parenthesis.h"
#include "../../literal/atom.h"

class MockObserverException {
};

class MockObserver: public RepositoryObserver {
public:
    void update(Repository *repository) {
        throw MockObserverException();
    }
};

TEST(LiteralsStackTest, Observer) {
    LiteralsStack stack;
    stack.attach(new MockObserver());

    EXPECT_EQ(0, stack.size());
    EXPECT_THROW(stack.pushAndNotify(LiteralPointer(new WhitespaceLiteral)), MockObserverException);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(stack.top()) != nullptr);
    EXPECT_EQ(1, stack.size());
    EXPECT_THROW(stack.pushAndNotify(LiteralPointer(new ParenthesisLiteral("("))), MockObserverException);
    EXPECT_TRUE(dynamic_pointer_cast<ParenthesisLiteral>(stack.top()) != nullptr);
    EXPECT_TRUE(dynamic_pointer_cast<WhitespaceLiteral>(stack.second()) != nullptr);
    EXPECT_EQ(2, stack.size());
    EXPECT_THROW(stack.popAndNotify(), MockObserverException);
    EXPECT_EQ(1, stack.size());
    EXPECT_THROW(stack.popAndNotify(), MockObserverException);
    EXPECT_EQ(0, stack.size());
}

TEST(LiteralsStackTest, Memento) {
    LiteralsStack stack;

    stack.push(LiteralPointer(new AtomLiteral("1")));
    stack.push(LiteralPointer(new AtomLiteral("2")));
    EXPECT_EQ(2, stack.size());

    stack.save();
    stack.push(LiteralPointer(new AtomLiteral("3")));
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("3", stack.top()->toString());
    EXPECT_EQ("2", stack.second()->toString());

    stack.save();
    stack.push(LiteralPointer(new AtomLiteral("4")));
    EXPECT_EQ(4, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
    EXPECT_EQ("3", stack.second()->toString());

    stack.save();

    stack.undo();
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("3", stack.top()->toString());
    EXPECT_EQ("2", stack.second()->toString());

    stack.undo();
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("2", stack.top()->toString());
    EXPECT_EQ("1", stack.second()->toString());

    stack.undo();
    EXPECT_EQ(0, stack.size());

    EXPECT_THROW(stack.undo(), RuntimeException);

    stack.redo();
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ("2", stack.top()->toString());
    EXPECT_EQ("1", stack.second()->toString());

    stack.redo();
    EXPECT_EQ(3, stack.size());
    EXPECT_EQ("3", stack.top()->toString());
    EXPECT_EQ("2", stack.second()->toString());

    stack.redo();
    EXPECT_EQ(4, stack.size());
    EXPECT_EQ("4", stack.top()->toString());
    EXPECT_EQ("3", stack.second()->toString());

    EXPECT_THROW(stack.redo(), RuntimeException);
}
