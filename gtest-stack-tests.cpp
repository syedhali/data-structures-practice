#include <iostream>

#include "Stack.hpp"
#include "gtest/gtest.h"

using namespace ds::stack;

class StackTest : public ::testing::Test {

protected:
    Node<int> *mTop = nullptr;
    Stack<int> *mStack = nullptr;

    StackTest() {
        mTop = new Node<int>(100, nullptr);
        mStack = new Stack<int>(mTop);
    }

    ~StackTest() {
        if (mStack != nullptr) {
            delete mStack;
        }
    }
};

TEST_F(StackTest, TopNodeIsValid) {
    ASSERT_EQ(mTop->getData(), 100);
    ASSERT_EQ(mTop->getNext(), nullptr);
}

TEST_F(StackTest, InitialValuesMatchTop) {
    ASSERT_EQ(mStack->getSize(), 1);
    ASSERT_EQ(mStack->peek(), mTop->getData());
}

TEST_F(StackTest, Push) {
    mStack->push(50);

    ASSERT_EQ(mStack->getSize(), 2);
    ASSERT_EQ(mStack->peek(), 50);
}

TEST_F(StackTest, Pop) {
    mStack->pop();

    ASSERT_EQ(mStack->getSize(), 0);
}