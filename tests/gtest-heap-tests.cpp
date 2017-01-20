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

TEST_F(HeapTest, Empty) {
    ASSERT_TRUE(true);
}