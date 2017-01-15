//
// Created by Syed Haris Ali on 1/14/17.
//

#include "Sort/Sort.h"
#include <iostream>

namespace ds {

    namespace sort {

        void Print(std::string identifier, std::vector<int> &list) {
            std::cout << identifier << " - List contains: [";
            for (int i = 0; i < list.size(); ++i) {
                std::cout << list[i];
                if (i == (int)list.size() - 1) {
                    std::cout << "]";
                }
                else {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }

        void Swap(std::vector<int> &list, int i, int j) {
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }

        void SelectionSort(std::vector<int> &list) {
            for (int i = 0; i < list.size(); ++i) {
                for (int j = i + 1; j < list.size(); ++j) {
                    if (list[i] > list[j]) {
                        Swap(list, i, j);
                    }
                }
            }
        }

        void BubbleSort(std::vector<int> &list) {
            for (int i = (int)list.size() - 1; i >= 0; --i) {
                bool swapped = false;
                for (int j = 0; j < i; ++j) {
                    if (list[j] > list[j + 1]) {
                        Swap(list, j, j + 1);
                        swapped = true;
                    }
                }
                if (!swapped) {
                    break;
                }
            }
        }

        void InsertionSort(std::vector<int> &list) {
            for (int i = 0; i < (int)list.size() - 1; ++i) {
                for (int j = i + 1; j > 0; --j) {
                    if (list[j] < list[j - 1]) {
                        Swap(list, j, j - 1);
                    } else {
                        break;
                    }
                }
            }
        }

    }

}