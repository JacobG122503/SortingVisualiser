#include "Algorithms.h"
#include <unistd.h>

// This is the delay in microseconds. Change to 0 if you want no delay
#define DELAY 20000

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
            PrintGraph(arr, min_idx, i);
        }
    }
}

int DualPivotQuickSort::Partition(std::vector<int> &arr, int low, int high, int *lp) {
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
        PrintGraph(arr, low, high);
    }

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {

        // if elements are less than the left pivot
        if (arr[k] < p) {
            std::swap(arr[k], arr[j]);
            PrintGraph(arr, k, j);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            std::swap(arr[k], arr[g]);
            PrintGraph(arr, k, g);
            g--;
            if (arr[k] < p) {
                std::swap(arr[k], arr[j]);
                PrintGraph(arr, k, j);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    std::swap(arr[low], arr[j]);
    PrintGraph(arr, low, j);
    std::swap(arr[high], arr[g]);
    PrintGraph(arr, high, g);

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
            PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne);
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo);
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

void BingoSort::MaxMin(std::vector<int> &vec, int n, int &bingo, int &nextBingo) {
    for (int i = 1; i < n; bingo = std::min(bingo, vec[i]), nextBingo = std::max(nextBingo, vec[i]), i++)
        ;
}

// Function to sort the array
void BingoSort::Sort(std::vector<int> &vec, int n) {
    int bingo = vec[0];
    int nextBingo = vec[0];
    MaxMin(vec, n, bingo, nextBingo);
    int largestEle = nextBingo;
    int nextElePos = 0;
    while (bingo < nextBingo) {
        // Will keep the track of the element position to
        // shifted to their correct position
        int startPos = nextElePos;
        for (int i = startPos; i < n; i++) {
            if (vec[i] == bingo) {
                std::swap(vec[i], vec[nextElePos]);
                PrintGraph(vec, i, nextElePos);
                nextElePos = nextElePos + 1;
            }
            // Here we are finding the next Bingo Element
            // for the next pass
            else if (vec[i] < nextBingo)
                nextBingo = vec[i];
        }
        bingo = nextBingo;
        nextBingo = largestEle;
    }
}

void PancakeSort::flip(std::vector<int> &arr, int i) {
    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        PrintGraph(arr, start, i);
        arr[i] = temp;
        start++;
        i--;
    }
}

int PancakeSort::findMax(std::vector<int> &arr, int n) {
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

void PancakeSort::Sort(std::vector<int> &arr, int n) {
    // Start from the complete
    // array and one by one
    // reduce current size
    // by one
    for (int curr_size = n; curr_size > 1;
         --curr_size) {
        // Find index of the
        // maximum element in
        // arr[0..curr_size-1]
        int mi = findMax(arr, curr_size);

        // Move the maximum
        // element to end of
        // current array if
        // it's not already
        // at the end
        if (mi != curr_size - 1) {
            // To move at the end,
            // first move maximum
            // number to beginning
            flip(arr, mi);

            // Now move the maximum
            // number to end by
            // reversing current array
            flip(arr, curr_size - 1);
        }
    }
}

void PrintGraph(std::vector<int> arr, int swap1, int swap2) {
    clear();
    for (int i = 0; i < (int)arr.size(); i++) {
        // Set color
        if (i == swap1 || i == swap2) {
            attron(COLOR_PAIR(COLOR_RED));
        } else {
            attron(COLOR_PAIR(COLOR_WHITE));
        }
        for (int j = 0; j <= arr[i]; j++) {
            mvprintw(getmaxy(stdscr) - j, i, "O");
        }
        // Turn color off
        if (i == swap1 || i == swap2) {
            attroff(COLOR_PAIR(COLOR_RED));
        } else {
            attroff(COLOR_PAIR(COLOR_WHITE));
        }
    }
    refresh();
    // This is a way to prevent flashing in terminal when sorting large data sets.
    usleep(DELAY * (getmaxx(stdscr) / 80));
}

/*

frequency by what the number is and do the number
*/