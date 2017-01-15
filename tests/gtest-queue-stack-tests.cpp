//
// Created by Syed Haris Ali on 1/13/17.
//

#include <gtest/gtest.h>
#include "Queue/StackQueue.h"

using namespace ds::queue;

class StackQueueTest : public ::testing::Test {
protected:
    StackQueue<int> mQueue;

    StackQueueTest() {
        mQueue = StackQueue<int>();
    }
};

TEST_F(StackQueueTest, UnderflowException) {
    ASSERT_THROW(mQueue.dequeue(), QueueUnderflowException);
}

TEST_F(StackQueueTest, OverflowException) {
    while (!mQueue.isFull()) {
        mQueue.enqueue(10);
    }
    ASSERT_THROW(mQueue.enqueue(10), QueueOverflowException);
}

TEST_F(StackQueueTest, EnqueueDequeue) {
    mQueue.enqueue(50);
    mQueue.enqueue(10);
    mQueue.enqueue(55);
    ASSERT_EQ(mQueue.dequeue(), 50);
    ASSERT_EQ(mQueue.dequeue(), 10);
    ASSERT_EQ(mQueue.dequeue(), 55);
}

TEST_F(StackQueueTest, EnqueueDequeue2) {
    mQueue.enqueue(1);
    mQueue.enqueue(2);
    ASSERT_EQ(mQueue.dequeue(), 1);
    mQueue.enqueue(3);
    ASSERT_EQ(mQueue.dequeue(), 2);
    ASSERT_EQ(mQueue.dequeue(), 3);
}