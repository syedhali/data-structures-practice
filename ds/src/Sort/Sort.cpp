//
// Created by Syed Haris Ali on 1/14/17.
//

#include "Sort/Sort.h"
#include <iostream>
#include <algorithm>

namespace ds {

    namespace sort {

        void InsertionSortWithIncrement(std::vector<int> &list, int startIndex, int increment);

        void Print(std::string identifier, std::vector<int> &list) {
            std::cout << identifier << " - List contains: [";
            for (int i = 0; i < list.size(); ++i) {
                std::cout << list[i];
                if (i == (int) list.size() - 1) {
                    std::cout << "]";
                } else {
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
            for (int i = (int) list.size() - 1; i >= 0; --i) {
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
            return InsertionSortWithIncrement(list, 0, 1);
        }

        void InsertionSortWithIncrement(std::vector<int> &list, int startIndex, int increment) {
            for (int i = startIndex; i < list.size(); i += increment) {
                for (int j = std::min(i + increment, (int)list.size() - 1); j - increment >= 0; j -= increment) {
                    if (list[j] < list[j - increment]) {
                        Swap(list, j, j - increment);
                    } else {
                        break;
                    }
                }
            }
        }

        void ShellSort(std::vector<int> &list) {
            int increment = (int)list.size() / 2;
            while (increment >= 1) {
                for (int i = 0; i < increment; ++i) {
                    InsertionSortWithIncrement(list, i, increment);
                }
                increment /= 2;
            }
        }

        namespace merge {

            void Split(std::vector<int> &list, std::vector<int> &left, std::vector<int> &right) {
                int size = (int)list.size();
                int half = size / 2;
                for (int i = 0; i + half < size; ++i) {
                    left[i] = list[i];
                    right[i] = list[i + half];
                }
            }

            void Merge(std::vector<int> &list, std::vector<int> &left, std::vector<int> &right) {

            }

        }

        void MergeSort(std::vector<int> &list) {
            std::cout << "Int test: " << 5/2 << std::endl;
        }
    }

}