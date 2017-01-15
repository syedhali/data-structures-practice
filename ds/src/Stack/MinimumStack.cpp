//
// Created by Syed Haris Ali on 1/13/17.
//

#include "Stack/MinimumStack.hpp"

namespace ds {

    namespace stack {

        MinimumStack::MinimumStack() {
            mMinimumStack = Stack<int>();
            mStack = Stack<int>();
        }

        int MinimumStack::getMinimum() throw(StackUnderflowException) {
            return mMinimumStack.peek();
        }

        int MinimumStack::peek() throw(StackUnderflowException) {
            return mStack.peek();
        }

        int MinimumStack::pop() throw(StackUnderflowException) {
            mMinimumStack.pop();
            return mStack.pop();
        }

        void MinimumStack::push(int data) throw(StackOverflowException) {
            int min = data;
            if (mMinimumStack.getSize() > 0) {
                int top = mMinimumStack.peek();
                if (top < data) {
                    min = top;
                }
            }
            mMinimumStack.push(min);
            mStack.push(data);
        }

    }

}