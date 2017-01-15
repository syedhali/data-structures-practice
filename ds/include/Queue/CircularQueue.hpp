//
// Created by Syed Haris Ali on 1/13/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_CIRCULARQUEUE_H
#define DATA_STRUCTURES_PRACTICE_CIRCULARQUEUE_H

#include <vector>
#include "Queue.hpp"

namespace ds {

    namespace queue {
        const int SPECIAL_INDEX = 0;

        template<typename T>
        class CircularQueue {
        private:
            std::vector<T> mArray;
            int mHeadIndex = SPECIAL_INDEX;
            int mTailIndex = SPECIAL_INDEX;

        public:
            CircularQueue() {
                mArray = std::vector<T>(QUEUE_MAX_SIZE);
            }

            ~CircularQueue() {

            }

            int capacity() {
                return (int)mArray.capacity();
            }

            void enqueue(T data) throw(QueueOverflowException) {
                if (isFull()) {
                    throw QueueOverflowException();
                }

                mTailIndex = (mTailIndex + 1) % capacity();
                mArray[mTailIndex] = data;

                if (mHeadIndex == SPECIAL_INDEX) {
                    mHeadIndex = mTailIndex;
                }
            }

            T dequeue() throw(QueueUnderflowException) {
                if (isEmpty()) {
                    throw QueueUnderflowException();
                }

                T data = mArray[mHeadIndex];

                if (mHeadIndex == mTailIndex) {
                    mHeadIndex = SPECIAL_INDEX;
                } else {
                    mHeadIndex = (mHeadIndex + 1) % capacity();
                }

                return data;
            }

            T peek() throw(QueueUnderflowException) {
                if (isEmpty()) {
                    throw QueueUnderflowException();
                }

                return mArray[mHeadIndex];
            }

            bool isFull() {
                int nextIndex = (mTailIndex + 1) % capacity();
                return nextIndex == mHeadIndex;
            }

            bool isEmpty() {
                return mHeadIndex == SPECIAL_INDEX;
            }
        };

    }

}


#endif //DATA_STRUCTURES_PRACTICE_CIRCULARQUEUE_H
