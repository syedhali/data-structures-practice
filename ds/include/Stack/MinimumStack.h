//
// Created by Syed Haris Ali on 1/13/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_MINIMUMSTACK_H
#define DATA_STRUCTURES_PRACTICE_MINIMUMSTACK_H

#include "Stack.hpp"

namespace ds {

    namespace stack {

        class MinimumStack {

        private:
            Stack<int> mStack;
            Stack<int> mMinimumStack;

        public:
            MinimumStack();

            int getMinimum() throw(StackUnderflowException);
            int peek() throw(StackUnderflowException);
            int pop() throw(StackUnderflowException);
            void push(int data) throw(StackOverflowException);
        };

    }

}


#endif //DATA_STRUCTURES_PRACTICE_MINIMUMSTACK_H
