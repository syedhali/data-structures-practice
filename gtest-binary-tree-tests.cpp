//
// Created by Syed Haris Ali on 1/12/17.
//

#include <gtest/gtest.h>
#include "Tree.hpp"

using namespace ds::tree::binary;

class BinaryTreeTest : public ::testing::Test {

protected:
    Node<int> *mRoot = nullptr;
    Tree<int> *mTree = nullptr;

    BinaryTreeTest() {
        mRoot = new Node<int>(100);
        mTree = new Tree<int>(mRoot);
    }

    ~BinaryTreeTest() {
        if (mTree != nullptr) {
            delete mTree;
        }
    }
};

TEST_F(BinaryTreeTest, RootNodeInitialValuesAreValid) {
    ASSERT_EQ(mRoot->getData(), 100);
    ASSERT_EQ(mRoot->getLeftChild(), nullptr);
    ASSERT_EQ(mRoot->getRightChild(), nullptr);
}

TEST_F(BinaryTreeTest, ChildLeavesAreValid) {
    mRoot->setLeftChild(new Node<int>(123));
    mRoot->setRightChild(new Node<int>(454));
    ASSERT_NE(mRoot->getLeftChild(), nullptr);
    ASSERT_NE(mRoot->getRightChild(), nullptr);
    ASSERT_EQ(mRoot->getLeftChild()->getData(), 123);
    ASSERT_EQ(mRoot->getRightChild()->getData(), 454);
}