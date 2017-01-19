//
// Created by Syed Haris Ali on 1/18/17.
//

#include "Tree/BinarySearchTree.h"

namespace ds {
    namespace tree {
        namespace binary {
            Node<int> *SearchTree::insert(Node<int> *head, Node<int> *node) {
                if (head == nullptr) {
                    return node;
                }

                if (node->getData() <= head->getData()) {
                    head->setLeftChild(insert(head->getLeftChild(), node));
                } else {
                    head->setRightChild(insert(head->getRightChild(), node));
                }

                std::cout << "head: " << head->getString(false) << std::endl;

                return head;
            }

            Node<int> *SearchTree::lookup(Node<int> *head, int data) {
                if (head == nullptr) {
                    return nullptr;
                }

                if (head->getData() == data) {
                    return head;
                }

                if (data <= head->getData()) {
                    return lookup(head->getLeftChild(), data);
                }
                else {
                    return lookup(head->getRightChild(), data);
                }
            }

            Node<int> *SearchTree::getRoot() {
                return mRoot;
            }

            void SearchTree::setRoot(Node<int> *root) {
                mRoot = root;
            }

            Node<int> *SearchTree::insert(Node<int> *node) {
                Node<int> *head = mRoot;
                return insert(head, node);
            }

            Node<int> *SearchTree::lookup(int data) {
                Node<int> *head = mRoot;
                return lookup(head, data);
            }
        }
    }
}