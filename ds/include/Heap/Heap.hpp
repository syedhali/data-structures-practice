//
// Created by Syed Haris Ali on 1/20/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_HEAP_H
#define DATA_STRUCTURES_PRACTICE_HEAP_H

namespace ds {

    namespace heap {

        const int MAX_SIZE = 40;

        class HeapFullException : std::runtime_error {
        public:
            HeapFullException() : std::runtime_error("Heap is full") {}
        };

        template<typename T>
        class Heap {
        private:
            std::vector<T> mElements = std::vector<T>();
            int mCount;
            int mMaxSize = MAX_SIZE;

        public:
            Heap() {}
            Heap(int maxSize) : mMaxSize(maxSize) {}
            ~Heap() {}

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

            void insert(T element) throw(HeapFullException) {
                if (isFull()) {
                    throw HeapFullException();
                }

                mElements[mCount] = element;
                siftUp(mCount);
                mCount++;
            }
        };

        template<typename T>
        class MinHeap : Heap<T> {
        public:
            virtual void siftDown(int index) override {
                int leftChildIndex = Heap<T>::getLeftChildIndex(index);
                int rightChildIndex = Heap<T>::getRightChildIndex(index);

                int smallerIndex = -1;
                if (leftChildIndex != -1 && rightChildIndex != -1) {
                    smallerIndex = Heap<T>::getElementAtIndex(leftChildIndex) < Heap<T>::getElementAtIndex(rightChildIndex) ? leftChildIndex : rightChildIndex;
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

                if (Heap<T>::getElementAtIndex(smallerIndex) < Heap<T>::getElementAtIndex(index)) {
                    Heap<T>::swap(smallerIndex, index);
                    siftDown(smallerIndex);
                }
            }

            virtual void siftUp(int index) override {
                int parentIndex = Heap<T>::getParentIndex(index);
                if (parentIndex == -1) {
                    return;
                }

                if (Heap<T>::getElementAtIndex(parentIndex) > Heap<T>::getElementAtIndex(index)) {
                    Heap<T>::swap(parentIndex, index);
                    siftUp(parentIndex);
                }
            }
        };

        template<typename T>
        class MaxHeap : Heap<T> {
        public:
            virtual void siftDown(int index) override {
                int leftChildIndex = Heap<T>::getLeftChildIndex(index);
                int rightChildIndex = Heap<T>::getRightChildIndex(index);

                int largerIndex = -1;
                if (leftChildIndex != -1 && rightChildIndex != -1) {
                    largerIndex = Heap<T>::getElementAtIndex(leftChildIndex) > Heap<T>::getElementAtIndex(rightChildIndex) ? leftChildIndex : rightChildIndex;
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

                if (Heap<T>::getElementAtIndex(largerIndex) > Heap<T>::getElementAtIndex(index)) {
                    Heap<T>::swap(largerIndex, index);
                    siftDown(largerIndex);
                }
            }

            virtual void siftUp(int index) override {
                int parentIndex = Heap<T>::getParentIndex(index);
                if (parentIndex == -1) {
                    return;
                }

                if (Heap<T>::getElementAtIndex(parentIndex) < Heap<T>::getElementAtIndex(index)) {
                    Heap<T>::swap(parentIndex, index);
                    siftUp(parentIndex);
                }
            }
        };
    }

}

#endif //DATA_STRUCTURES_PRACTICE_HEAP_H
