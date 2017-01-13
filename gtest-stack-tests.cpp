#include <iostream>

#include "Stack/Stack.hpp"
#include "gtest/gtest.h"

using namespace ds::stack;

class StackTest : public ::testing::Test {

protected:
    Stack<int> *mStack = nullptr;

    StackTest() {
        mStack = new Stack<int>();
    }

    ~StackTest() {
        if (mStack != nullptr) {
            delete mStack;
        }
    }
};

TEST_F(StackTest, InitialValues) {
    ASSERT_EQ(mStack->getSize(), 0);
}

TEST_F(StackTest, IsEmpty) {
    ASSERT_TRUE(mStack->isEmpty());
}

TEST_F(StackTest, IsFull) {
    ASSERT_FALSE(mStack->isFull());
    for (int i = 0; i < STACK_MAX_SIZE; ++i) {
        mStack->push(i);
    }
    ASSERT_TRUE(mStack->isFull());
}

TEST_F(StackTest, Push) {
    mStack->push(50);
    ASSERT_EQ(mStack->getSize(), 1);
    ASSERT_EQ(mStack->peek(), 50);
}

TEST_F(StackTest, Pop) {
    mStack->push(100);
    ASSERT_EQ(mStack->getSize(), 1);
    ASSERT_EQ(mStack->peek(), 100);

    mStack->pop();
    ASSERT_EQ(mStack->getSize(), 0);
    ASSERT_THROW(mStack->peek(), StackUnderflowException);
    ASSERT_THROW(mStack->pop(), StackUnderflowException);
}