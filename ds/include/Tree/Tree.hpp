//
//  Tree.hpp
//  data-structures-cpp-practice
//
//  Created by Syed Haris Ali on 1/6/17.
//  Copyright © 2017 Syed Haris Ali. All rights reserved.
//

#ifndef DS_TREE_HPP
#define DS_TREE_HPP

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Queue/CircularQueue.hpp"

namespace ds {
    namespace tree {
        namespace binary {

            template<class T>
            struct Node {
            private:
                T mData;
                Node *mLeftChild = nullptr;
                Node *mRightChild = nullptr;

            public:
                Node() {}

                Node(T data) {
                    mData = data;
                }

                ~Node() {
                    if (mLeftChild != nullptr) {
                        delete mLeftChild;
                    }
                    if (mRightChild != nullptr) {
                        delete mRightChild;
                    }
                }

                T getData() const {
                    return mData;
                }

                void setData(T data) {
                    mData = data;
                }

                Node *getLeftChild() const {
                    return mLeftChild;
                }

                void setLeftChild(Node *leftChild) {
                    mLeftChild = leftChild;
                }

                Node *getRightChild() const {
                    return mRightChild;
                }

                void setRightChild(Node *rightChild) {
                    mRightChild = rightChild;
                }

                std::string getString(bool includeChildren) {
                    std::stringstream ss;
                    ss << "Node (" << getData() << ")";
                    if (includeChildren) {
                        ss << " { " << std::endl;
                        if (mLeftChild != nullptr) {
                            ss << "leftChild: " << mLeftChild->getString(includeChildren);
                        } else {
                            ss << "leftChild: null" << std::endl;
                        }
                        if (mRightChild != nullptr) {
                            ss << "rightChild: " << mRightChild->getString(includeChildren);
                        } else {
                            ss << "rightChild: null" << std::endl;
                        }
                        ss << "}" << std::endl;
                    }
                    return ss.str();
                }
            };

            template<class T>
            class Tree {
            private:
                Node<T> *mRoot = nullptr;

            protected:
                void depthFirstTraversalPreorder(Node<T> *root, std::vector<Node<T> *> &visitedNodes) {
                    if (root == nullptr) {
                        return;
                    }
                    visitedNodes.push_back(root);
                    depthFirstTraversalPreorder(root->getLeftChild(), visitedNodes);
                    depthFirstTraversalPreorder(root->getRightChild(), visitedNodes);
                }

                void depthFirstTraversalInorder(Node<T> *root, std::vector<Node<T> *> &visitedNodes) {
                    if (root == nullptr) {
                        return;
                    }
                    depthFirstTraversalInorder(root->getLeftChild(), visitedNodes);
                    visitedNodes.push_back(root);
                    depthFirstTraversalInorder(root->getRightChild(), visitedNodes);
                }

                void depthFirstTraversalPostorder(Node<T> *root, std::vector<Node<T> *> &visitedNodes) {
                    if (root == nullptr) {
                        return;
                    }
                    depthFirstTraversalPostorder(root->getLeftChild(), visitedNodes);
                    depthFirstTraversalPostorder(root->getRightChild(), visitedNodes);
                    visitedNodes.push_back(root);
                }

                void mirror(Node<T> *head) {
                    if (head == nullptr) {
                        return;
                    }

                    if (head->getLeftChild() == nullptr && head->getRightChild() == nullptr) {
                        return;
                    }

                    Node<T> *temp = head->getLeftChild();
                    head->setLeftChild(head->getRightChild());
                    head->setRightChild(temp);

                    mirror(head->getLeftChild());
                    mirror(head->getRightChild());
                }

            public:
                Tree(Node<T> *root) : mRoot(root) {}
                ~Tree() {}

                static int countTrees(int numNodes) {
                    if (numNodes <= 1) {
                        return 1;
                    }

                    int sum = 0;
                    for (int i = 1; i <= numNodes; ++i) {
                        int countLeftTrees = countTrees(i - 1);
                        int countRightTrees = countTrees(numNodes - i);
                        sum = sum + (countLeftTrees * countRightTrees);
                    }

                    return sum;
                }

                Node<T> *getRoot() const {
                    return mRoot;
                }

                void setRoot(Node<T> *root) {
                    mRoot = root;
                }

                std::vector<Node<T> *> breadthFirstTraversal() {
                    std::vector<Node<T> *> visitedNodes = std::vector<Node<T> *>();
                    if (mRoot == nullptr) {
                        return visitedNodes;
                    }

                    queue::CircularQueue<Node<T> *> queue = queue::CircularQueue<Node<T> *>();
                    queue.enqueue(mRoot);
                    while (!queue.isEmpty()) {
                        Node<T> *node = queue.dequeue();
                        visitedNodes.push_back(node);

                        if (node->getLeftChild() != nullptr) {
                            queue.enqueue(node->getLeftChild());
                        }

                        if (node->getRightChild() != nullptr) {
                            queue.enqueue(node->getRightChild());
                        }
                    }

                    return visitedNodes;
                }

                std::vector<Node<T> *> depthFirstTraversalPreorder() {
                    std::vector<Node<T> *> visitiedNodes = std::vector<Node<T> *>();
                    if (mRoot == nullptr) {
                        return visitiedNodes;
                    }
                    depthFirstTraversalPreorder(mRoot, visitiedNodes);
                    return visitiedNodes;
                }

                std::vector<Node<T> *> depthFirstTraversalInorder() {
                    std::vector<Node<T> *> visitiedNodes = std::vector<Node<T> *>();
                    if (mRoot == nullptr) {
                        return visitiedNodes;
                    }
                    depthFirstTraversalInorder(mRoot, visitiedNodes);
                    return visitiedNodes;
                }

                std::vector<Node<T> *> depthFirstTraversalPostorder() {
                    std::vector<Node<T> *> visitiedNodes = std::vector<Node<T> *>();
                    if (mRoot == nullptr) {
                        return visitiedNodes;
                    }
                    depthFirstTraversalPostorder(mRoot, visitiedNodes);
                    return visitiedNodes;
                }

                void mirror() {
                    mirror(mRoot);
                }
            };

        }
    }
}

#endif /* DS_TREE_HPP */
