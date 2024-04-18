#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <ncurses.h>

class QuickSort {
public:
    int Partition(std::vector<int> &arr, int start, int end);
    void Sort(std::vector<int> &arr, int start, int end);
};

#endif