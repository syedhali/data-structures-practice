//
// Created by Syed Haris Ali on 1/12/17.
//

#include <gtest/gtest.h>
#include "Tree/Tree.hpp"

using namespace ds::tree::binary;

class BinaryTreeTest : public ::testing::Test {

protected:
    Node<std::string> *mRootWithChildren = nullptr;
    Node<std::string> *mRoot = nullptr;
    Tree<std::string> *mTree = nullptr;

    BinaryTreeTest() {
        mRoot = new Node<std::string>("root");
        mTree = new Tree<std::string>(mRoot);
        populateChildren();
    }

    ~BinaryTreeTest() {
        if (mTree != nullptr) {
            delete mTree;
        }
        if (mRoot != nullptr) {
            delete mRoot;
        }
        if (mRootWithChildren != nullptr) {
            delete mRootWithChildren;
        }
    }

public:
    void populateChildren() {
        Node<std::string> *nodeA = new Node<std::string>("A");
        Node<std::string> *nodeB = new Node<std::string>("B");
        Node<std::string> *nodeC = new Node<std::string>("C");
        Node<std::string> *nodeD = new Node<std::string>("D");
        Node<std::string> *nodeE = new Node<std::string>("E");
        Node<std::string> *nodeF = new Node<std::string>("F");
        Node<std::string> *nodeG = new Node<std::string>("G");
        Node<std::string> *nodeH = new Node<std::string>("H");
        Node<std::string> *nodeI = new Node<std::string>("I");
        Node<std::string> *nodeJ = new Node<std::string>("J");
        nodeA->setLeftChild(nodeB);
        nodeA->setRightChild(nodeC);
        nodeB->setLeftChild(nodeD);
        nodeB->setRightChild(nodeE);
        nodeC->setLeftChild(nodeF);
        nodeC->setRightChild(nodeG);
        nodeG->setLeftChild(nodeH);
        nodeH->setLeftChild(nodeI);
        nodeH->setRightChild(nodeJ);
        mRootWithChildren = nodeA;
    }
};

TEST_F(BinaryTreeTest, RootNodeInitialValuesAreValid) {
    ASSERT_EQ(mRoot->getData(), "root");
    ASSERT_EQ(mRoot->getLeftChild(), nullptr);
    ASSERT_EQ(mRoot->getRightChild(), nullptr);
}

TEST_F(BinaryTreeTest, ChildLeavesAreValid) {
    mRoot->setLeftChild(new Node<std::string>("left"));
    mRoot->setRightChild(new Node<std::string>("right"));
    ASSERT_NE(mRoot->getLeftChild(), nullptr);
    ASSERT_NE(mRoot->getRightChild(), nullptr);
    ASSERT_EQ(mRoot->getLeftChild()->getData(), "left");
    ASSERT_EQ(mRoot->getRightChild()->getData(), "right");
}

TEST_F(BinaryTreeTest, BreadFirstTraversal) {
    mTree->setRoot(mRootWithChildren);
    std::vector<Node<std::string> *> visitedNodes = mTree->breadthFirst();
    ASSERT_EQ(visitedNodes[0]->getData(), "A");
    ASSERT_EQ(visitedNodes[1]->getData(), "B");
    ASSERT_EQ(visitedNodes[2]->getData(), "C");
    ASSERT_EQ(visitedNodes[3]->getData(), "D");
    ASSERT_EQ(visitedNodes[4]->getData(), "E");
    ASSERT_EQ(visitedNodes[5]->getData(), "F");
    ASSERT_EQ(visitedNodes[6]->getData(), "G");
    ASSERT_EQ(visitedNodes[7]->getData(), "H");
    ASSERT_EQ(visitedNodes[8]->getData(), "I");
    ASSERT_EQ(visitedNodes[9]->getData(), "J");
}