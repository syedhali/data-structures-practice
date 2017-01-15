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
            std::map<const char, const char> mMatchingMap;
            std::list<const char> mMatchingList;

        public:
            ExpressionValidator();

            bool validate(std::string input);
        };

    }

}

#endif //DS_EXPRESSIONVALIDATOR_H
