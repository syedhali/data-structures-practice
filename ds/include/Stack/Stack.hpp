//
// Created by Syed Haris Ali on 1/12/17.
// Copyright (c) 2017 Syed Haris Ali. All rights reserved.
//

#ifndef DS_STACK_H
#define DS_STACK_H

#include <exception>
#include <string>
#include <sstream>

namespace ds {
    namespace stack {

        const int STACK_MAX_SIZE = 40;

        template<class T>
        class Node {
        private:
            T mData;
            Node *mNext = nullptr;

        public:
            Node(T data, Node *next) : mData(data), mNext(next) {}

            ~Node() {
                if (mNext != nullptr) {
                    delete mNext;
                }
            }

            T getData() {
                return mData;
            }

            void setData(T data) {
                mData = data;
            }

            Node *getNext() {
                return mNext;
            }

            void setNext(Node *next) {
                mNext = next;
            }

            std::string getString() {
                std::stringstream ss;
                ss << std::endl << "Node (" << getData() << ") { " << std::endl;
                if (mNext != nullptr) {
                    ss << "next: " << mNext->getString();
                } else {
                    ss << "next: null" << std::endl;
                }
                ss << "}" << std::endl;
                return ss.str();
            }

        };

        class StackOverflowException : std::runtime_error {
        public:
            StackOverflowException() : runtime_error("Stack overflow") {}
        };

        class StackUnderflowException : std::runtime_error {
        public:
            StackUnderflowException() : runtime_error("Stack underflow") {}
        };

        template<class T>
        class Stack {
        private:
            Node<T> * mTop = nullptr;
            int mSize = 0;

        public:
            Stack() {

            }

            ~Stack() {
                if (mTop != nullptr) {
                    delete mTop;
                }
            }

            void push(T data) throw(StackOverflowException) {
                if (mSize == STACK_MAX_SIZE) {
                    throw StackOverflowException();
                }

                Node<T> *node = new Node<T>(data, mTop);
                mTop = node;
                mSize++;

            }

            T pop() throw(StackUnderflowException) {
                if (mSize == 0) {
                    throw StackUnderflowException();
                }

                T data = mTop->getData();

                Node<T> *next = mTop->getNext();
                mTop->setNext(nullptr);
                delete mTop;
                mTop = next;
                mSize--;

                return data;
            }

            T peek() throw(StackUnderflowException) {
                if (mSize == 0) {
                    throw StackUnderflowException();
                }

                return mTop->getData();
            }

            bool isEmpty() {
                return mSize == 0;
            }

            bool isFull() {
                return mSize == STACK_MAX_SIZE;
            }

            int getSize() {
                return mSize;
            }

        };
    }
}

#endif //DS_STACK_H