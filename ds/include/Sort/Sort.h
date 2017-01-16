//
// Created by Syed Haris Ali on 1/14/17.
//

#ifndef DATA_STRUCTURES_PRACTICE_SORT_H
#define DATA_STRUCTURES_PRACTICE_SORT_H

#include <vector>

namespace ds {
    namespace sort {

        //
        // Simply prints out a list with an identifier to help denote where the print statement is coming from
        //
        void Print(std::string identifier, std::vector<int> &list);

        //
        // Complexity:       O(N^2)
        // Space Complexity: O(1)
        // Notes:
        //
        void SelectionSort(std::vector<int> &list);

        //
        // Complexity:       O(N^2)
        // Space Complexity: O(1)
        // Notes:
        //
        void BubbleSort(std::vector<int> &list);

        //
        // Complexity:       O(N^2)
        // Space Complexity: O(1)
        // Notes:            Useful for faster, divide and conquer algorithms
        //                   Better than bubble sort because it can break early on each iteration to the sorted list
        //                   Uses less RAM than bubble sort because there are fewer swaps occurring
        //
        void InsertionSort(std::vector<int> &list);

        //
        // Complexity:       Between O(N) - O(N^2), depending on increment value chosen
        // Space Complexity: O(1)
        // Notes:            Better than Insertion sort because final list is a nearly sorted list
        //
        void ShellSort(std::vector<int> &list);
    }
}

#endif //DATA_STRUCTURES_PRACTICE_SORT_H
