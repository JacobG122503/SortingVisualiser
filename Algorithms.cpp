#include "Algorithms.h"
#include <unistd.h>

void PrintGraph(std::vector<int> arr, int swap1, int swap2);

int QuickSort::Partition(std::vector<int> &arr, int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    PrintGraph(arr, pivotIndex, start);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
            PrintGraph(arr, i-1, j+1);
        }
    }

    return pivotIndex;
}

void QuickSort::Sort(std::vector<int> &arr, int start, int end) {
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = Partition(arr, start, end);

    // Sorting the left part
    Sort(arr, start, p - 1);

    // Sorting the right part
    Sort(arr, p + 1, end);
}

void PrintGraph(std::vector<int> arr, int swap1, int swap2) {
    clear();
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == swap1 || i == swap2) attron(COLOR_PAIR(COLOR_RED) | A_BOLD);
        for (int j = 0; j <= arr[i]; j++) {
            mvprintw(24 - j, i, "O");
        }
        if (i == swap1 || i == swap2) attroff(COLOR_PAIR(COLOR_RED) | A_BOLD);
    }
    usleep(50000);
    refresh();
}