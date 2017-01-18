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

                std::string getString() {
                    std::stringstream ss;
                    ss << std::endl << "Node (" << getData() << ") { " << std::endl;
                    if (mLeftChild != nullptr) {
                        ss << "leftChild: " << mLeftChild->getString();
                    } else {
                        ss << "leftChild: null" << std::endl;
                    }
                    if (mRightChild != nullptr) {
                        ss << "rightChild: " << mRightChild->getString();
                    } else {
                        ss << "rightChild: null" << std::endl;
                    }
                    ss << "}" << std::endl;
                    return ss.str();
                }
            };

            template<class T>
            class Tree {
            private:
                Node<T> *mRoot = nullptr;

            public:
                Tree(Node<T> *root) : mRoot(root) {}

                ~Tree() {
                    if (mRoot != nullptr) {
                        delete mRoot;
                    }
                }

                Node<T> *getRoot() const {
                    return mRoot;
                }

                void setRoot(Node<T> *root) {
                    mRoot = root;
                }
            };

        }
    }
}

#endif /* DS_TREE_HPP */
