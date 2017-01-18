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

            public:
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

            public:
                Tree(Node<T> *root) : mRoot(root) {}
                ~Tree() {}

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

                void depthFirstTraversalPreorder(Node<T> *root, std::vector<Node<T> *> &visitedNodes) {
                    if (root == nullptr) {
                        return;
                    }
                    visitedNodes.push_back(root);
                    depthFirstTraversalPreorder(root->getLeftChild(), visitedNodes);
                    depthFirstTraversalPreorder(root->getRightChild(), visitedNodes);
                }
            };

        }
    }
}

#endif /* DS_TREE_HPP */
