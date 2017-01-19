//
// Created by Syed Haris Ali on 1/18/17.
//

#include "Tree/BinarySearchTree.h"

namespace ds {
    namespace tree {
        namespace binary {
            bool SearchTree::isBinarySearchTree(Node<int> *root) {
                if (root == nullptr) {
                    return true;
                }

                if (root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
                    return true;
                }

                if ((root->getLeftChild()->getData() < root->getData()) &&
                    root->getRightChild()->getData() > root->getData()) {
                    return isBinarySearchTree(root->getLeftChild()) && isBinarySearchTree(root->getRightChild());
                }

                return false;
            }

            Node<int> *SearchTree::insert(Node<int> *head, Node<int> *node) {
                if (head == nullptr) {
                    return node;
                }
                if (node->getData() <= head->getData()) {
                    head->setLeftChild(insert(head->getLeftChild(), node));
                } else {
                    head->setRightChild(insert(head->getRightChild(), node));
                }
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

            int SearchTree::minimumValue(Node<int> *head) {
                if (head == nullptr) {
                    return MINIMUM_VALUE_NOT_FOUND;
                }

                if (head->getLeftChild() != nullptr) {
                    return minimumValue(head->getLeftChild());
                }

                return head->getData();
            }

            int SearchTree::maximumDepth(Node<int> *head) {
                if (head == nullptr) {
                    return 0;
                }

                if (head->getLeftChild() == nullptr && head->getRightChild() == nullptr) {
                    return 0;
                }

                int left = maximumDepth(head->getLeftChild()) + 1;
                int right = maximumDepth(head->getRightChild()) + 1;

                return std::max(left, right);
            }

            void SearchTree::nodesInRange(int low, int high, Node<int> *head, std::vector<Node<int> *> &validNodes) {
                if (head == nullptr) {
                    return;
                }

                if (head->getData() >= low && head->getData() <= high) {
                    validNodes.push_back(head);
                }

                if (head->getData() > low) {
                    nodesInRange(low, high, head->getLeftChild(), validNodes);
                }

                if (head->getData() < high) {
                    nodesInRange(low, high, head->getRightChild(), validNodes);
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

            int SearchTree::minimumValue() {
                Node<int> *head = mRoot;
                return minimumValue(head);
            }

            int SearchTree::maximumDepth() {
                Node<int> *head = mRoot;
                return maximumDepth(head);
            }

            std::vector<Node<int> *> SearchTree::nodesInRange(int low, int high) {
                Node<int> *head = mRoot;
                std::vector<Node<int> *> validNodes = std::vector<Node<int> *>();
                nodesInRange(low, high, head, validNodes);
                return validNodes;
            }
        }
    }
}