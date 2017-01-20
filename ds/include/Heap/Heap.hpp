//
// Created by Syed Haris Ali on 1/20/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_HEAP_H
#define DATA_STRUCTURES_PRACTICE_HEAP_H

namespace ds {

    namespace heap {

        const int MAX_SIZE = 40;

        template<typename T>
        class Heap {
        private:
            std::vector<T> mElements = std::vector<T>();
            int mCount;
            int mMaxSize = MAX_SIZE;

        public:
            Heap() {

            }

            Heap(int maxSize) : mMaxSize(maxSize) {

            }

            ~Heap() {

            }

            T getElementAtIndex(int index) {
                return mElements[index];
            }

            int getLeftChildIndex(int index) {
                index = 2 * index + 1;
                if (index >= mCount) {
                    return -1;
                }
                return index;
            }

            int getParentIndex(int index) {
                if (index < 0 || index > mCount) {
                    return -1;
                }
                return (index - 1) / 2;
            }

            int getRightChildIndex(int index) {
                index = 2 * index + 2;
                if (index >= mCount) {
                    return -1;
                }
                return index;

            }

            int getCount() {
                return mCount;
            }

            bool isEmpty() {
                return mCount == 0;
            }

            bool isFull() {
                return mCount == mMaxSize;
            }

            void swap(int i, int j) {
                T temp = mElements[i];
                mElements[i] = mElements[j];
                mElements[j] = temp;
            }

            virtual void siftDown(int index) {}
            virtual void siftUp(int index) {}
        };

        template<typename T>
        class MinHeap : Heap<T> {
        public:
            virtual void siftDown(int index) override {
                int leftChildIndex = getLeftChildIndex(index);
                int rightChildIndex = getRightChildIndex(index);

                int smallerIndex = -1;
                if (leftChildIndex != -1 && rightChildIndex != -1) {
                    smallerIndex = getElementAtIndex(leftChildIndex) < getElementAtIndex(rightChildIndex) ? leftChildIndex : rightChildIndex;
                }
                else if (leftChildIndex != -1) {
                    smallerIndex = leftChildIndex;
                }
                else if (rightChildIndex != -1) {
                    smallerIndex = rightChildIndex;
                }

                if (smallerIndex == -1) {
                    return;
                }

                if (getElementAtIndex(smallerIndex) < getElementAtIndex(index)) {
                    swap(smallerIndex, index);
                    siftDown(smallerIndex);
                }
            }

            virtual void siftUp(int index) override {
                int parentIndex = getParentIndex(index);
                if (parentIndex == -1) {
                    return;
                }

                if (getElementAtIndex(parentIndex) > getElementAtIndex(index)) {
                    swap(parentIndex, index);
                    siftUp(parentIndex);
                }
            }
        };

        template<typename T>
        class MaxHeap : Heap<T> {
        public:
            virtual void siftDown(int index) override {
                int leftChildIndex = getLeftChildIndex(index);
                int rightChildIndex = getRightChildIndex(index);

                int largerIndex = -1;
                if (leftChildIndex != -1 && rightChildIndex != -1) {
                    largerIndex = getElementAtIndex(leftChildIndex) > getElementAtIndex(rightChildIndex) ? leftChildIndex : rightChildIndex;
                }
                else if (leftChildIndex != -1) {
                    largerIndex = leftChildIndex;
                }
                else if (rightChildIndex != -1) {
                    largerIndex = rightChildIndex;
                }

                if (largerIndex == -1) {
                    return;
                }

                if (getElementAtIndex(largerIndex) > getElementAtIndex(index)) {
                    swap(largerIndex, index);
                    siftDown(largerIndex);
                }
            }

            virtual void siftUp(int index) override {
                int parentIndex = getParentIndex(index);
                if (parentIndex == -1) {
                    return;
                }

                if (getElementAtIndex(parentIndex) < getElementAtIndex(index)) {
                    swap(parentIndex, index);
                    siftUp(parentIndex);
                }
            }
        };
    }

}

#endif //DATA_STRUCTURES_PRACTICE_HEAP_H
