//
// Created by Syed Haris Ali on 1/14/17.
//

#include <gtest/gtest.h>
#include "Sort/Sort.h"

using namespace ds::sort;

class SortTest : public ::testing::Test {
protected:
    std::vector<int> mUnsortedList;

    SortTest() {
        mUnsortedList = std::vector<int>();
        mUnsortedList.push_back(5);
        mUnsortedList.push_back(3);
        mUnsortedList.push_back(9);
        mUnsortedList.push_back(1);
        mUnsortedList.push_back(10);
        mUnsortedList.push_back(8);
        mUnsortedList.push_back(2);
        mUnsortedList.push_back(4);
        mUnsortedList.push_back(7);
        mUnsortedList.push_back(6);
    }
};

TEST_F(SortTest, SelectionSortTest) {
    SelectionSort(mUnsortedList);
    for (int i = 0; i < mUnsortedList.size() - 1; ++i) {
        ASSERT_TRUE(mUnsortedList[i] < mUnsortedList[i + 1]);
    }
}

TEST_F(SortTest, BubbleSortTest) {
    BubbleSort(mUnsortedList);
    for (int i = 0; i < mUnsortedList.size() - 1; ++i) {
        ASSERT_TRUE(mUnsortedList[i] < mUnsortedList[i + 1]);
    }
}