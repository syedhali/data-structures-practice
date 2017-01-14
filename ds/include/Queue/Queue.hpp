//
// Created by Syed Haris Ali on 1/13/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_QUEUE_H
#define DATA_STRUCTURES_PRACTICE_QUEUE_H

namespace ds {

    namespace queue {

        const int QUEUE_MAX_SIZE = 40;

        class QueueOverflowException : std::runtime_error {
        public:
            QueueOverflowException() : std::runtime_error("Queue overflow exception"){
            }
        };

        class QueueUnderflowException : std::runtime_error {
        public:
            QueueUnderflowException() : std::runtime_error("Queue underflow exception"){
            }
        };

        template<typename T>
        class Node {
        private:
            T mData;
            Node<T> *mLast = nullptr;

        public:
            Node(T data) : mData(data) {}
            ~Node() {
                if (mLast != nullptr) {
                    delete mLast;
                }
            }

            T getData() {
                return mData;
            }

            void setData(T data) {
                mData = data;
            }

            Node<T> *getLast() {
                return mLast;
            }

            void setLast(Node<T> *last) {
                mLast = last;
            }
        };

        template<typename T>
        class Queue {
        private:
            int mSize;
            Node<T> *mHead = nullptr;
            Node<T> *mTail = nullptr;

        public:
            Queue() {
                mSize = 0;
            }

            ~Queue() {
                if (mTail != nullptr) {
                    delete mTail;
                }
            }

            void enqueue(T data) throw(QueueOverflowException) {
                if (mSize == QUEUE_MAX_SIZE) {
                    throw QueueOverflowException();
                }

                Node<T> *node = new Node<T>(data);
                if (mSize == 0) {
                    mHead = node;
                }
                else {
                    mTail->setLast(node);
                }
                mTail = node;
                mSize++;
            }

            T dequeue() throw(QueueUnderflowException) {
                if (mSize == 0) {
                    throw QueueUnderflowException();
                }

                Node<T> *head = mHead;
                int data = head->getData();
                mHead = head->getLast();
                mSize--;

                head->setLast(nullptr);
                delete head;
                if (mSize == 0) {
                    mTail = nullptr;
                }

                return data;
            }

            T peek() throw(QueueUnderflowException) {
                if (mSize == 0) {
                    throw QueueUnderflowException();
                }

                return mHead->getData();
            }

            int getSize() {
                return mSize;
            }
        };

    }

}

#endif //DATA_STRUCTURES_PRACTICE_QUEUE_H
