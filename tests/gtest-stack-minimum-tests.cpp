//
// Created by Syed Haris Ali on 1/13/17.
//

#include <gtest/gtest.h>
#include "Stack/MinimumStack.hpp"

using namespace ds::stack;

class MinimumStackTests : public ::testing::Test {
protected:
    MinimumStack mStack;

public:
    MinimumStackTests(){
        mStack = MinimumStack();
    }
    ~MinimumStackTests(){}
};

TEST_F(MinimumStackTests, ThrowsUnderflowForEmptyStack) {
    ASSERT_THROW(mStack.peek(), StackUnderflowException);
    ASSERT_THROW(mStack.pop(), StackUnderflowException);
}

TEST_F(MinimumStackTests, Push1) {
    mStack.push(10);
    ASSERT_EQ(mStack.peek(), 10);
    ASSERT_EQ(mStack.getMinimum(), 10);
}

TEST_F(MinimumStackTests, Push2) {
    mStack.push(10);
    ASSERT_EQ(mStack.peek(), 10);
    ASSERT_EQ(mStack.getMinimum(), 10);
    mStack.push(5);
    ASSERT_EQ(mStack.peek(), 5);
    ASSERT_EQ(mStack.getMinimum(), 5);
    mStack.push(3);
    ASSERT_EQ(mStack.peek(), 3);
    ASSERT_EQ(mStack.getMinimum(), 3);
    mStack.push(9);
    ASSERT_EQ(mStack.peek(), 9);
    ASSERT_EQ(mStack.getMinimum(), 3);
}

TEST_F(MinimumStackTests, Push3) {
    mStack.push(1);
    ASSERT_EQ(mStack.peek(), 1);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.push(2);
    ASSERT_EQ(mStack.peek(), 2);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.push(2);
    ASSERT_EQ(mStack.peek(), 2);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.push(3);
    ASSERT_EQ(mStack.peek(), 3);
    ASSERT_EQ(mStack.getMinimum(), 1);
}

TEST_F(MinimumStackTests, Push4) {
    mStack.push(3);
    ASSERT_EQ(mStack.peek(), 3);
    ASSERT_EQ(mStack.getMinimum(), 3);
    mStack.push(1);
    ASSERT_EQ(mStack.peek(), 1);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.push(2);
    ASSERT_EQ(mStack.peek(), 2);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.push(0);
    ASSERT_EQ(mStack.peek(), 0);
    ASSERT_EQ(mStack.getMinimum(), 0);
}

TEST_F(MinimumStackTests, Pop) {
    mStack.push(5);
    mStack.push(2);
    mStack.push(2);
    mStack.push(4);
    mStack.push(1);
    mStack.push(6);
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.pop();
    ASSERT_EQ(mStack.getMinimum(), 1);
    mStack.pop();
    ASSERT_EQ(mStack.getMinimum(), 2);
}

