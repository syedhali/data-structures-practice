//
// Created by Syed Haris Ali on 1/12/17.
//

#include "Stack/ExpressionValidator.h"
#include "Stack/Stack.hpp"

namespace ds {

    namespace stack {

        ExpressionValidator::ExpressionValidator() {
            mMatchingMap = std::map<const char, const char>();
            mMatchingMap.insert(std::make_pair('{', '}'));
            mMatchingMap.insert(std::make_pair('(', ')'));
            mMatchingMap.insert(std::make_pair('[', ']'));
            mMatchingList = std::list<const char>();
            for (auto it : mMatchingMap) {
                mMatchingList.push_back(it.first);
                mMatchingList.push_back(it.second);
            }
        }

        bool ExpressionValidator::validate(std::string input) {
            Stack<const char> stack = Stack<const char>();
            for (const char i : input) {
                bool match = false;
                for (const char s : mMatchingList) {
                    if (i == s) {
                        match = true;
                        break;
                    }
                }
                if (match) {
                    if (!stack.isEmpty()) {
                        const char top = stack.peek();
                        if (mMatchingMap.count(top)) {
                            if (mMatchingMap.at(top) == i) {
                                stack.pop();
                                continue;
                            }
                        }
                    }
                    stack.push(i);
                }

            }
            bool valid = stack.isEmpty();
            return valid;
        }

    }

}