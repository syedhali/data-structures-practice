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
    std::vector<Node<std::string> *> visitedNodes = mTree->breadthFirstTraversal();
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

TEST_F(BinaryTreeTest, DepthFirstPreorderTraversal) {
    mTree->setRoot(mRootWithChildren);
    std::vector<Node<std::string> *> visitedNodes = mTree->depthFirstTraversalPreorder();
    ASSERT_EQ(visitedNodes[0]->getData(), "A");
    ASSERT_EQ(visitedNodes[1]->getData(), "B");
    ASSERT_EQ(visitedNodes[2]->getData(), "D");
    ASSERT_EQ(visitedNodes[3]->getData(), "E");
    ASSERT_EQ(visitedNodes[4]->getData(), "C");
    ASSERT_EQ(visitedNodes[5]->getData(), "F");
    ASSERT_EQ(visitedNodes[6]->getData(), "G");
    ASSERT_EQ(visitedNodes[7]->getData(), "H");
    ASSERT_EQ(visitedNodes[8]->getData(), "I");
    ASSERT_EQ(visitedNodes[9]->getData(), "J");
}

TEST_F(BinaryTreeTest, DepthFirstInorderTraversal) {
    mTree->setRoot(mRootWithChildren);
    std::vector<Node<std::string> *> visitedNodes = mTree->depthFirstTraversalInorder();
    ASSERT_EQ(visitedNodes[0]->getData(), "D");
    ASSERT_EQ(visitedNodes[1]->getData(), "B");
    ASSERT_EQ(visitedNodes[2]->getData(), "E");
    ASSERT_EQ(visitedNodes[3]->getData(), "A");
    ASSERT_EQ(visitedNodes[4]->getData(), "F");
    ASSERT_EQ(visitedNodes[5]->getData(), "C");
    ASSERT_EQ(visitedNodes[6]->getData(), "I");
    ASSERT_EQ(visitedNodes[7]->getData(), "H");
    ASSERT_EQ(visitedNodes[8]->getData(), "J");
    ASSERT_EQ(visitedNodes[9]->getData(), "G");
}

TEST_F(BinaryTreeTest, DepthFirstPostorderTraversal) {
    mTree->setRoot(mRootWithChildren);
    std::vector<Node<std::string> *> visitedNodes = mTree->depthFirstTraversalPostorder();
    ASSERT_EQ(visitedNodes[0]->getData(), "D");
    ASSERT_EQ(visitedNodes[1]->getData(), "E");
    ASSERT_EQ(visitedNodes[2]->getData(), "B");
    ASSERT_EQ(visitedNodes[3]->getData(), "F");
    ASSERT_EQ(visitedNodes[4]->getData(), "I");
    ASSERT_EQ(visitedNodes[5]->getData(), "J");
    ASSERT_EQ(visitedNodes[6]->getData(), "H");
    ASSERT_EQ(visitedNodes[7]->getData(), "G");
    ASSERT_EQ(visitedNodes[8]->getData(), "C");
    ASSERT_EQ(visitedNodes[9]->getData(), "A");
}

TEST_F(BinaryTreeTest, MirrorWiithBreadthFirstTraversal) {
    mTree->setRoot(mRootWithChildren);
    mTree->mirror();
    std::vector<Node<std::string> *> visitedNodes = mTree->breadthFirstTraversal();
    ASSERT_EQ(visitedNodes[0]->getData(), "A");
    ASSERT_EQ(visitedNodes[1]->getData(), "C");
    ASSERT_EQ(visitedNodes[2]->getData(), "B");
    ASSERT_EQ(visitedNodes[3]->getData(), "G");
    ASSERT_EQ(visitedNodes[4]->getData(), "F");
    ASSERT_EQ(visitedNodes[5]->getData(), "E");
    ASSERT_EQ(visitedNodes[6]->getData(), "D");
    ASSERT_EQ(visitedNodes[7]->getData(), "H");
    ASSERT_EQ(visitedNodes[8]->getData(), "J");
    ASSERT_EQ(visitedNodes[9]->getData(), "I");
}

TEST_F(BinaryTreeTest, UniqueTreesForNNodes) {
    ASSERT_EQ(Tree<int>::countTrees(0), 1);
    ASSERT_EQ(Tree<int>::countTrees(1), 1);
    ASSERT_EQ(Tree<int>::countTrees(2), 2);
    ASSERT_EQ(Tree<int>::countTrees(3), 5);
    ASSERT_EQ(Tree<int>::countTrees(4), 14);
    ASSERT_EQ(Tree<int>::countTrees(5), 42);
    ASSERT_EQ(Tree<int>::countTrees(6), 132);
    ASSERT_EQ(Tree<int>::countTrees(7), 429);
    ASSERT_EQ(Tree<int>::countTrees(8), 1430);
    ASSERT_EQ(Tree<int>::countTrees(9), 4862);
    ASSERT_EQ(Tree<int>::countTrees(10), 16796);
}

TEST_F(BinaryTreeTest, DoesPathExistEqualToSum) {
    Node<int> *node1 = new Node<int>(1);
    Node<int> *node3 = new Node<int>(3);
    Node<int> *node5 = new Node<int>(5);
    Node<int> *node7 = new Node<int>(7);
    Node<int> *node9 = new Node<int>(9);
    node1->setLeftChild(node3);
    node1->setRightChild(node5);
    node5->setLeftChild(node7);
    node5->setRightChild(node9);
    ASSERT_TRUE(Tree<int>::doesPathExistEqualToSum(4, node1));
    ASSERT_TRUE(Tree<int>::doesPathExistEqualToSum(13, node1));
    ASSERT_TRUE(Tree<int>::doesPathExistEqualToSum(15, node1));
    ASSERT_FALSE(Tree<int>::doesPathExistEqualToSum(0, node1));
    ASSERT_FALSE(Tree<int>::doesPathExistEqualToSum(-1, node1));
    ASSERT_FALSE(Tree<int>::doesPathExistEqualToSum(20, node1));
}

TEST_F(BinaryTreeTest, PrintAllPaths) {
    mTree->setRoot(mRootWithChildren);
    std::vector<std::vector<Node<std::string> *>> allLists = std::vector<std::vector<Node<std::string> *>>();
    std::vector<Node<std::string> *> pathList = std::vector<Node<std::string> *>();
    Tree<std::string>::printPaths(mTree->getRoot(), pathList, allLists);
    ASSERT_EQ(allLists.size(), 5);
}

TEST_F(BinaryTreeTest, PrintAllPaths2) {
    std::vector<std::vector<Node<std::string> *>> allLists = std::vector<std::vector<Node<std::string> *>>();
    std::vector<Node<std::string> *> pathList = std::vector<Node<std::string> *>();
    Tree<std::string>::printPaths(mTree->getRoot(), pathList, allLists);
    ASSERT_EQ(allLists.size(), 1);
}

TEST_F(BinaryTreeTest, PrintAllPathsNull) {
    std::vector<std::vector<Node<std::string> *>> allLists = std::vector<std::vector<Node<std::string> *>>();
    std::vector<Node<std::string> *> pathList = std::vector<Node<std::string> *>();
    Tree<std::string>::printPaths(nullptr, pathList, allLists);
    ASSERT_EQ(allLists.size(), 0);
}