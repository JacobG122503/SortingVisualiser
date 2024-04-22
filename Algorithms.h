#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <ncurses.h>
#include <vector>

class Algorithms {
public:
    static int delay;
    void static PrintGraph(std::vector<int> arr, int swap1, int swap2);
};

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

class SelectionSort {
public:
    void Sort(std::vector<int> &arr, int n);
};

class DualPivotQuickSort {
public:
    int Partition(std::vector<int> &arr, int low, int high, int *lp);
    void Sort(std::vector<int> &arr, int low, int high);
};

class MergeSort {
public:
    void merge(std::vector<int> &array, int const left, int const mid, int const right);
    void Sort(std::vector<int> &array, int const begin, int const end);
};

class BingoSort {
public:
    void MaxMin(std::vector<int> &vec, int n, int &bingo, int &nextBingo);
    void Sort(std::vector<int> &vec, int n);
};

class PancakeSort {
public: 
    void flip(std::vector<int> &arr, int i);
    int findMax(std::vector<int> &arr, int n);
    void Sort(std::vector<int> &arr, int n);
};

class CombSort {
public:
    int getNextGap(int gap);
    void Sort(std::vector<int> &a, int n);
};

#endif