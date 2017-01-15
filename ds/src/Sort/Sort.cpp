//
// Created by Syed Haris Ali on 1/14/17.
//

#include "Sort/Sort.h"

namespace ds {

    namespace sort {

        void Swap(std::vector<int> &list, int i, int j) {
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }

        //
        // Performance: O(N^2)
        //
        void SelectionSort(std::vector<int> &list) {
            for (int i = 0; i < list.size(); ++i) {
                for (int j = i + 1; j < list.size(); ++j) {
                    if (list[i] > list[j]) {
                        Swap(list, i, j);
                    }
                }
            }
        }

        //
        // Performance: O(N^2)
        //
        void BubbleSort(std::vector<int> &list) {
            for (int i = 0; i < list.size(); ++i) {
                bool swapped = false;
                for (int j = (int)list.size() - 1; j > i; --j) {
                    if (list[j] < list[j - 1]) {
                        Swap(list, j, j - 1);
                        swapped = true;
                    }
                }
                if (!swapped) {
                    break;
                }
            }
        }
    }

}