//
// Created by Syed Haris Ali on 1/13/17.
//

#include <gtest/gtest.h>
#include "Queue/CircularQueue.h"

using namespace ds::queue;

class CircularQueueTest : public ::testing::Test {
protected:
    CircularQueue<int> mCircularQueue;

    CircularQueueTest() {
        mCircularQueue = CircularQueue<int>();
    }
};

TEST_F(CircularQueueTest, InitialValuesAreValid) {
    ASSERT_EQ(mCircularQueue.isEmpty(), true);
    ASSERT_EQ(mCircularQueue.isFull(), false);
}

TEST_F(CircularQueueTest, UnderflowException) {
    ASSERT_THROW(mCircularQueue.peek(), QueueUnderflowException);
    ASSERT_THROW(mCircularQueue.dequeue(), QueueUnderflowException);
}

TEST_F(CircularQueueTest, Enqueue) {
    mCircularQueue.enqueue(50);
    ASSERT_EQ(mCircularQueue.peek(), 50);
}

TEST_F(CircularQueueTest, Enqueue2) {
    mCircularQueue.enqueue(50);
    ASSERT_EQ(mCircularQueue.peek(), 50);
    mCircularQueue.enqueue(10);
    ASSERT_EQ(mCircularQueue.peek(), 50);
    mCircularQueue.enqueue(55);
    ASSERT_EQ(mCircularQueue.peek(), 50);
}

TEST_F(CircularQueueTest, Dequeue) {
    mCircularQueue.enqueue(50);
    mCircularQueue.enqueue(10);
    mCircularQueue.enqueue(55);
    ASSERT_EQ(mCircularQueue.dequeue(), 50);
    ASSERT_EQ(mCircularQueue.dequeue(), 10);
    ASSERT_EQ(mCircularQueue.dequeue(), 55);
}