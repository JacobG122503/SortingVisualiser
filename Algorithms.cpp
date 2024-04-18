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
            PrintGraph(arr, i - 1, j + 1);
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

void InsertionSort::Sort(std::vector<int> &arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            PrintGraph(arr, j + 1, j);
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort::Sort(std::vector<int> &arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                PrintGraph(arr, j, j + 1);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void PrintGraph(std::vector<int> arr, int swap1, int swap2) {
    clear();
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == swap1 || i == swap2)
            attron(COLOR_PAIR(COLOR_RED) | A_BOLD);
        for (int j = 0; j <= arr[i]; j++) {
            mvprintw(getmaxy(stdscr) - j, i, "O");
        }
        if (i == swap1 || i == swap2)
            attroff(COLOR_PAIR(COLOR_RED) | A_BOLD);
    }
    refresh();
    usleep(20000);
}