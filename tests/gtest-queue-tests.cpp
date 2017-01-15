//
// Created by Syed Haris Ali on 1/13/17.
//

#include <gtest/gtest.h>
#include "Queue/Queue.hpp"

using namespace ds::queue;

class QueueTests : public ::testing::Test {
protected:
    Queue<int> mQueue;

    QueueTests() {
        mQueue = Queue<int>();
    }
};

TEST_F(QueueTests, InitialValuesAreValid) {
    ASSERT_EQ(mQueue.getSize(), 0);
}

TEST_F(QueueTests, Enqueue) {
    mQueue.enqueue(10);
    ASSERT_EQ(mQueue.peek(), 10);
    ASSERT_EQ(mQueue.getSize(), 1);
}

TEST_F(QueueTests, Enqueue2) {
    mQueue.enqueue(10);
    mQueue.enqueue(20);
    ASSERT_EQ(mQueue.peek(), 10);
    ASSERT_EQ(mQueue.getSize(), 2);
}

TEST_F(QueueTests, Enqueue3) {
    mQueue.enqueue(10);
    mQueue.enqueue(20);
    mQueue.enqueue(30);
    ASSERT_EQ(mQueue.peek(), 10);
    ASSERT_EQ(mQueue.getSize(), 3);
}

TEST_F(QueueTests, Dequeue) {
    ASSERT_THROW(mQueue.dequeue(), QueueUnderflowException);
    mQueue.enqueue(10);
    mQueue.enqueue(4);
    mQueue.enqueue(55);
    mQueue.enqueue(33);
    mQueue.enqueue(7);
    ASSERT_EQ(mQueue.getSize(), 5);
    ASSERT_EQ(mQueue.dequeue(), 10);
    ASSERT_EQ(mQueue.getSize(), 4);
    ASSERT_EQ(mQueue.dequeue(), 4);
    ASSERT_EQ(mQueue.getSize(), 3);
    ASSERT_EQ(mQueue.dequeue(), 55);
    ASSERT_EQ(mQueue.getSize(), 2);
    ASSERT_EQ(mQueue.dequeue(), 33);
    ASSERT_EQ(mQueue.getSize(), 1);
    ASSERT_EQ(mQueue.dequeue(), 7);
    ASSERT_EQ(mQueue.getSize(), 0);
}