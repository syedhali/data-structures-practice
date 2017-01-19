//
// Created by Syed Haris Ali on 1/18/17.
//

#include <gtest/gtest.h>
#include "Tree/BinarySearchTree.h"

using namespace ds::tree::binary;

class BinarySearchTreeTest : public ::testing::Test {
protected:
    Node<int> *mRootWithChildren;
    SearchTree *mTree;

    BinarySearchTreeTest() {
        populateChildren();

        mTree = new SearchTree();
        mTree->setRoot(mRootWithChildren);
    }

    ~BinarySearchTreeTest() {
        if (mTree != nullptr) {
            delete mTree;
        }
        if (mRootWithChildren != nullptr) {
            delete mRootWithChildren;
        }
    }

    void populateChildren() {
        Node<int> *node1 = new Node<int>(1);
        Node<int> *node0 = new Node<int>(0);
        Node<int> *node3 = new Node<int>(3);
        Node<int> *node2 = new Node<int>(2);
        Node<int> *node8 = new Node<int>(8);
        Node<int> *node5 = new Node<int>(5);
        Node<int> *node10 = new Node<int>(10);
        node1->setLeftChild(node0);
        node1->setRightChild(node3);
        node3->setLeftChild(node2);
        node3->setRightChild(node8);
        node8->setLeftChild(node5);
        node8->setRightChild(node10);
        mRootWithChildren = node1;
    }
};

TEST_F(BinarySearchTreeTest, Insertion) {
    Node<int> *head = mTree->insert(new Node<int>(4));
    ASSERT_TRUE(head != nullptr);
    ASSERT_EQ(head->getData(), 1);
}

TEST_F(BinarySearchTreeTest, Lookup) {
    Node<int> *node = mTree->lookup(5);
    ASSERT_TRUE(node != nullptr);
    ASSERT_EQ(node->getData(), 5);
}

TEST_F(BinarySearchTreeTest, LookupDoesNotExist) {
    Node<int> *node = mTree->lookup(1111);
    ASSERT_FALSE(node != nullptr);
}