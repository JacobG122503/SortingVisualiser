#include "Algorithms.h"

void PrintGraph(std::vector<int> arr);

void QuickSort::Sort() {
    PrintGraph(arr);
}

void PrintGraph(std::vector<int> arr) {

    for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = 0; j <= arr[i]; j++) {
            mvprintw(24-j, i, "O");
        }
    }

    refresh();
}