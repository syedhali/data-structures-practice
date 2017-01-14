//
// Created by Syed Haris Ali on 1/13/17.
//

#include <gtest/gtest.h>
#include "Queue/CircularQueue.h"

using namespace ds::queue;

class CircularQueueTest : public ::testing::Test {
protected:
    CircularQueue<int> mQueue;

    CircularQueueTest() {
        mQueue = CircularQueue<int>();
    }
};

TEST_F(CircularQueueTest, InitialValuesAreValid) {
    ASSERT_EQ(mQueue.isEmpty(), true);
    ASSERT_EQ(mQueue.isFull(), false);
}

TEST_F(CircularQueueTest, UnderflowException) {
    ASSERT_THROW(mQueue.peek(), QueueUnderflowException);
    ASSERT_THROW(mQueue.dequeue(), QueueUnderflowException);
}

TEST_F(CircularQueueTest, Enqueue) {
    mQueue.enqueue(50);
    ASSERT_EQ(mQueue.peek(), 50);
}

TEST_F(CircularQueueTest, Enqueue2) {
    mQueue.enqueue(50);
    ASSERT_EQ(mQueue.peek(), 50);
    mQueue.enqueue(10);
    ASSERT_EQ(mQueue.peek(), 50);
    mQueue.enqueue(55);
    ASSERT_EQ(mQueue.peek(), 50);
}

TEST_F(CircularQueueTest, Dequeue) {
    mQueue.enqueue(50);
    mQueue.enqueue(10);
    mQueue.enqueue(55);
    ASSERT_EQ(mQueue.dequeue(), 50);
    ASSERT_EQ(mQueue.dequeue(), 10);
    ASSERT_EQ(mQueue.dequeue(), 55);
    ASSERT_TRUE(mQueue.isEmpty());
}

TEST_F(CircularQueueTest, Dequeue2) {
    mQueue.enqueue(1);
    mQueue.enqueue(2);
    ASSERT_EQ(mQueue.dequeue(), 1);
    mQueue.enqueue(3);
    ASSERT_EQ(mQueue.dequeue(), 2);
    ASSERT_EQ(mQueue.dequeue(), 3);
    ASSERT_TRUE(mQueue.isEmpty());
}