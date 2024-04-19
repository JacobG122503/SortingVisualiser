#include "Algorithms.h"
#include <unistd.h>

void PrintGraph(std::vector<int> arr, int swap1, int swap2, int amount);

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
    PrintGraph(arr, pivotIndex, start, 2);

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
            PrintGraph(arr, i - 1, j + 1, 2);
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
            PrintGraph(arr, j + 1, j, 1);
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
                PrintGraph(arr, j, j + 1, 1);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void SelectionSort::Sort(std::vector<int> &arr, int n) {
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
            PrintGraph(arr, min_idx, i, 1);
        }
    }
}

int DualPivotQuickSort::Partition(std::vector<int> &arr, int low, int high, int *lp) {
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
        PrintGraph(arr, low, high, 6);
    }

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (arr[k] < p) {
            std::swap(arr[k], arr[j]);
            PrintGraph(arr, k, j, 6);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            std::swap(arr[k], arr[g]);
            PrintGraph(arr, k, g, 6);
            g--;
            if (arr[k] < p) {
                std::swap(arr[k], arr[j]);
                PrintGraph(arr, k, j, 6);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    std::swap(arr[low], arr[j]);
    PrintGraph(arr, low, j, 6);
    std::swap(arr[high], arr[g]);
    PrintGraph(arr, high, g, 6);

    // returning the indices of the pivots.
    *lp = j; // because we cannot return two elements
    // from a function.

    return g;
}

void DualPivotQuickSort::Sort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = Partition(arr, low, high, &lp);
        Sort(arr, low, lp - 1);
        Sort(arr, lp + 1, rp - 1);
        Sort(arr, rp + 1, high);
    }
}

void MergeSort::merge(std::vector<int> &array, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne, 4);
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo, 4);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne, 4);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo, 4);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void MergeSort::Sort(std::vector<int> &array, int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    Sort(array, begin, mid);
    Sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void PrintGraph(std::vector<int> arr, int swap1, int swap2, int amount) {
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
    // Some sorting algorithms have more swaps than others so this is a way to even the playing field.
    usleep(20000 / amount);
}