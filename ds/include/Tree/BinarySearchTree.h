//
// Created by Syed Haris Ali on 1/18/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H

#include "Tree/Tree.hpp"

namespace ds {
    namespace tree {
        namespace binary {
            class SearchTree {
            private:
                Node<int> *mRoot;

            protected:
                Node<int> *insert(Node<int> *head, Node<int> *node);
                Node<int> *lookup(Node<int> *head, int data);

            public:
                Node<int> *getRoot();
                void setRoot(Node<int> *root);
                Node<int> *insert(Node<int> *node);
                Node<int> *lookup(int data);
            };
        }

    }

}


#endif //DATA_STRUCTURES_PRACTICE_BINARYSEARCHTREE_H
