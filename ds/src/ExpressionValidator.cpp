//
// Created by Syed Haris Ali on 1/12/17.
//

#include "Stack/ExpressionValidator.hpp"
#include "Stack/Stack.hpp"

namespace ds {

    namespace stack {

        bool ExpressionValidator::validate(std::string input) {
            Stack<const char> *stack = new Stack<const char>();

            for (const char i : input) {

                bool match = false;
                for (const char s : *mMatchingList) {
                    if (i == s) {
                        match = true;
                        break;
                    }
                }

                if (match) {
                    if (!stack->isEmpty()) {
                        const char top = stack->peek();
                        if (mMatchingMap->count(top)) {
                            if (mMatchingMap->at(top) == i) {
                                stack->pop();
                                continue;
                            }
                        }
                    }
                    stack->push(i);
                }

            }

            bool valid = stack->isEmpty();

            delete stack;
            return valid;
        }

    }

}