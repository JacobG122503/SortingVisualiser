#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <ncurses.h>
#include <vector>

class QuickSort {
public:
    int Partition(std::vector<int> &arr, int start, int end);
    void Sort(std::vector<int> &arr, int start, int end);
};

class InsertionSort {
public:
    void Sort(std::vector<int> &arr, int n);
};

class BubbleSort {
public:
    void Sort(std::vector<int> &arr, int n);
};

#endif