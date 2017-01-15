//
// Created by Syed Haris Ali on 1/13/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_STACKQUEUE_H
#define DATA_STRUCTURES_PRACTICE_STACKQUEUE_H

#include "Queue/Queue.hpp"
#include "Stack/Stack.hpp"

namespace ds {

    namespace queue {

        using namespace stack;

        template <typename T>
        class StackQueue {
        private:
            Stack<T> mForwardStack;
            Stack<T> mReverseStack;

        public:
            StackQueue() {
                mForwardStack = Stack<T>();
                mReverseStack = Stack<T>();
            }

            void enqueue(T data) throw(QueueOverflowException, QueueUnderflowException) {
                if (isFull()) {
                    throw QueueOverflowException();
                }

                try {
                    while (!mReverseStack.isEmpty()) {
                        mForwardStack.push(mReverseStack.pop());
                    }
                    mForwardStack.push(data);
                } catch (StackOverflowException e) {
                    throw QueueOverflowException();
                } catch (StackUnderflowException e) {
                    throw QueueUnderflowException();
                }
            }

            T dequeue() throw(QueueOverflowException, QueueUnderflowException) {
                if (isEmpty()) {
                    throw QueueUnderflowException();
                }

                try {
                    while (!mForwardStack.isEmpty()) {
                        mReverseStack.push(mForwardStack.pop());
                    }
                    return mReverseStack.pop();
                } catch (StackOverflowException e) {
                    throw QueueOverflowException();
                } catch (StackUnderflowException e) {
                    throw QueueUnderflowException();
                }
            }

            bool isEmpty() {
                return mForwardStack.isEmpty() && mReverseStack.isEmpty();
            }

            bool isFull() {
                return mForwardStack.isFull() || mReverseStack.isFull();
            }
        };

    }

}

#endif //DATA_STRUCTURES_PRACTICE_STACKQUEUE_H
