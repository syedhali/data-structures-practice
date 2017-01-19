//
// Created by Syed Haris Ali on 1/18/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H

#include "Tree/Tree.hpp"

namespace ds {
    namespace tree {
        namespace binary {
            const int MINIMUM_VALUE_NOT_FOUND = -999;

            class SearchTree {
            private:
                Node<int> *mRoot;

            protected:
                Node<int> *insert(Node<int> *head, Node<int> *node);
                Node<int> *lookup(Node<int> *head, int data);
                int minimumValue(Node<int> *head);
                int maximumDepth(Node<int> *head);
                void nodesInRange(int low, int high, Node<int> *head, std::vector<Node<int> *> &validNodes);

            public:
                Node<int> *getRoot();
                void setRoot(Node<int> *root);
                Node<int> *insert(Node<int> *node);
                Node<int> *lookup(int data);
                int maximumDepth();
                int minimumValue();
                std::vector<Node<int> *> nodesInRange(int low, int high);
            };
        }

    }

}


#endif //DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H
