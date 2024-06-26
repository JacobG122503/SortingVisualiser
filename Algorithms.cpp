#include "Algorithms.h"
#include <unistd.h>

int QuickSort::Partition(std::vector<int> &arr, int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    Algorithms::PrintGraph(arr, pivotIndex, start);

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
            Algorithms::PrintGraph(arr, i - 1, j + 1);
        }
    }

    return pivotIndex;
}

void QuickSort::Sort(std::vector<int> &arr, int start, int end) {
    if (start >= end)
        return;

    int p = Partition(arr, start, end);

    Sort(arr, start, p - 1);

    Sort(arr, p + 1, end);
}

void InsertionSort::Sort(std::vector<int> &arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            Algorithms::PrintGraph(arr, j + 1, j);
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
                Algorithms::PrintGraph(arr, j, j + 1);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void SelectionSort::Sort(std::vector<int> &arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
            Algorithms::PrintGraph(arr, min_idx, i);
        }
    }
}

int DualPivotQuickSort::Partition(std::vector<int> &arr, int low, int high, int *lp) {
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
        Algorithms::PrintGraph(arr, low, high);
    }

    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {

        if (arr[k] < p) {
            std::swap(arr[k], arr[j]);
            Algorithms::PrintGraph(arr, k, j);
            j++;
        }

        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            std::swap(arr[k], arr[g]);
            Algorithms::PrintGraph(arr, k, g);
            g--;
            if (arr[k] < p) {
                std::swap(arr[k], arr[j]);
                Algorithms::PrintGraph(arr, k, j);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    std::swap(arr[low], arr[j]);
    Algorithms::PrintGraph(arr, low, j);
    std::swap(arr[high], arr[g]);
    Algorithms::PrintGraph(arr, high, g);

    *lp = j;

    return g;
}

void DualPivotQuickSort::Sort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
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

    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            Algorithms::PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne);
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            Algorithms::PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        Algorithms::PrintGraph(array, indexOfMergedArray, indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        Algorithms::PrintGraph(array, indexOfMergedArray, indexOfSubArrayTwo);
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

void BingoSort::Sort(std::vector<int> &vec, int n) {
    int bingo = vec[0];
    int nextBingo = vec[0];
    MaxMin(vec, n, bingo, nextBingo);
    int largestEle = nextBingo;
    int nextElePos = 0;
    while (bingo < nextBingo) {
        int startPos = nextElePos;
        for (int i = startPos; i < n; i++) {
            if (vec[i] == bingo) {
                std::swap(vec[i], vec[nextElePos]);
                Algorithms::PrintGraph(vec, i, nextElePos);
                nextElePos = nextElePos + 1;
            } else if (vec[i] < nextBingo)
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
        Algorithms::PrintGraph(arr, start, i);
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
    for (int curr_size = n; curr_size > 1;
         --curr_size) {
        int mi = findMax(arr, curr_size);

        if (mi != curr_size - 1) {
            flip(arr, mi);

            flip(arr, curr_size - 1);
        }
    }
}

int CombSort::getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void CombSort::Sort(std::vector<int> &a, int n) {
    int gap = n;

    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = getNextGap(gap);

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                std::swap(a[i], a[i + gap]);
                Algorithms::PrintGraph(a, i, i + gap);
                swapped = true;
            }
        }
    }
}

void GnomeSort::Sort(std::vector<int> &arr, int n) {
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            Algorithms::PrintGraph(arr, index, index - 1);
            index--;
        }
    }
    return;
}

int Algorithms::delay = 20000;

void Algorithms::PrintGraph(std::vector<int> arr, int swap1, int swap2) {
    erase(); // Erase prevents screen flashing
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

    usleep(Algorithms::delay);
}