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

    ~HeapTest() {

    }
};

TEST_F(HeapTest, MinHeapEmpty) {
    ASSERT_TRUE(mMinHeap.getCount() == 0);
    ASSERT_EQ(mMinHeap.getParentIndex(0), 0);
    ASSERT_EQ(mMinHeap.getRightChildIndex(0), -1);
    ASSERT_EQ(mMinHeap.getLeftChildIndex(0), -1);
}

TEST_F(HeapTest, Insertion) {
    mMinHeap.insert(10);
}