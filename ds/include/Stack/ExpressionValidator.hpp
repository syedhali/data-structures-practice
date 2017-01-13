//
// Created by Syed Haris Ali on 1/12/17.
//

#ifndef DS_EXPRESSIONVALIDATOR_H
#define DS_EXPRESSIONVALIDATOR_H

#include <map>
#include <list>
#include <string>
#include <iostream>

namespace ds {

    namespace stack {

        class ExpressionValidator {

        private:
            std::map<const char, const char> *mMatchingMap = nullptr;
            std::list<const char> *mMatchingList = nullptr;

        public:
            ExpressionValidator() {
                mMatchingMap = new std::map<const char, const char>();
                mMatchingMap->insert(std::make_pair('{', '}'));
                mMatchingMap->insert(std::make_pair('(', ')'));
                mMatchingMap->insert(std::make_pair('[', ']'));
                mMatchingList = new std::list<const char>();
                for (auto it : *mMatchingMap) {
                    mMatchingList->push_back(it.first);
                    mMatchingList->push_back(it.second);
                }
            }

            ~ExpressionValidator() {
                if (mMatchingMap != nullptr) {
                    delete mMatchingMap;
                }
                if (mMatchingList != nullptr) {
                    delete mMatchingList;
                }
            }

            bool validate(std::string input);
        };

    }

}

#endif //DS_EXPRESSIONVALIDATOR_H
