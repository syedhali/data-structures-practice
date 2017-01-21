//
// Created by Syed Haris Ali on 1/20/17.
//

#include <gtest/gtest.h>
#include "Heap/Heap.hpp"

using namespace ds::heap;

class HeapTest : public ::testing::Test {
protected:
    MinHeap<int> mMinHeap;
    MaxHeap<int> mMaxHeap;

    HeapTest() {
        mMinHeap = MinHeap<int>();
        mMaxHeap = MaxHeap<int>();
    }
};

TEST_F(HeapTest, MinHeapEmpty) {
    ASSERT_EQ(mMinHeap.getCount(), 0);
    ASSERT_EQ(mMinHeap.getParentIndex(0), -1);
    ASSERT_EQ(mMinHeap.getRightChildIndex(0), -1);
    ASSERT_EQ(mMinHeap.getLeftChildIndex(0), -1);
}

TEST_F(HeapTest, MinHeapInsertionFull) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        ASSERT_NO_THROW(mMinHeap.insert(i));
    }
    ASSERT_THROW(mMinHeap.insert(100), HeapFullException);
}

TEST_F(HeapTest, MinHeapInsertion) {
    ASSERT_NO_THROW(mMinHeap.insert(10));
    ASSERT_EQ(mMinHeap.getCount(), 1);
    ASSERT_EQ(mMinHeap.getElementAtIndex(0), 10);
    ASSERT_NO_THROW(mMinHeap.insert(2));
    ASSERT_EQ(mMinHeap.getCount(), 2);
    ASSERT_EQ(mMinHeap.getElementAtIndex(0), 2);
    ASSERT_EQ(mMinHeap.getElementAtIndex(1), 10);
    ASSERT_NO_THROW(mMinHeap.insert(12));
    ASSERT_EQ(mMinHeap.getCount(), 3);
    ASSERT_EQ(mMinHeap.getElementAtIndex(0), 2);
    ASSERT_EQ(mMinHeap.getElementAtIndex(1), 10);
    ASSERT_EQ(mMinHeap.getElementAtIndex(2), 12);
}

TEST_F(HeapTest, MinHeapRemove) {
    ASSERT_NO_THROW(mMinHeap.insert(1));
    ASSERT_NO_THROW(mMinHeap.insert(2));
    ASSERT_NO_THROW(mMinHeap.insert(3));
    ASSERT_NO_THROW(mMinHeap.insert(4));
    ASSERT_NO_THROW(mMinHeap.insert(5));
    ASSERT_NO_THROW(mMinHeap.insert(6));

    int highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 1);
    highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 2);
    highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 3);
    highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 4);
    highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 5);
    highestPriorityElement = mMinHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 6);
}

TEST_F(HeapTest, MaxHeapEmpty) {
    ASSERT_EQ(mMaxHeap.getCount(), 0);
    ASSERT_EQ(mMaxHeap.getParentIndex(0), -1);
    ASSERT_EQ(mMaxHeap.getRightChildIndex(0), -1);
    ASSERT_EQ(mMaxHeap.getLeftChildIndex(0), -1);
}

TEST_F(HeapTest, MaxHeapInsertionFull) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        ASSERT_NO_THROW(mMaxHeap.insert(i));
    }
    ASSERT_THROW(mMaxHeap.insert(100), HeapFullException);
}

TEST_F(HeapTest, MaxHeapInsertion) {
    ASSERT_NO_THROW(mMaxHeap.insert(10));
    ASSERT_EQ(mMaxHeap.getCount(), 1);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(0), 10);
    ASSERT_NO_THROW(mMaxHeap.insert(2));
    ASSERT_EQ(mMaxHeap.getCount(), 2);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(0), 10);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(1), 2);
    ASSERT_NO_THROW(mMaxHeap.insert(12));
    ASSERT_EQ(mMaxHeap.getCount(), 3);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(0), 12);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(1), 2);
    ASSERT_EQ(mMaxHeap.getElementAtIndex(2), 10);
}

TEST_F(HeapTest, MaxHeapRemove) {
    ASSERT_NO_THROW(mMaxHeap.insert(1));
    ASSERT_NO_THROW(mMaxHeap.insert(2));
    ASSERT_NO_THROW(mMaxHeap.insert(3));
    ASSERT_NO_THROW(mMaxHeap.insert(4));
    ASSERT_NO_THROW(mMaxHeap.insert(5));
    ASSERT_NO_THROW(mMaxHeap.insert(6));

    int highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 6);
    highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 5);
    highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 4);
    highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 3);
    highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 2);
    highestPriorityElement = mMaxHeap.removeHighestPriority();
    ASSERT_EQ(highestPriorityElement, 1);
}