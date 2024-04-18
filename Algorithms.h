#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <ncurses.h>

class QuickSort {
public:
    std::vector<int> arr;
    QuickSort(std::vector<int> arr) : arr(arr) {};
    void Sort();
};

#endif