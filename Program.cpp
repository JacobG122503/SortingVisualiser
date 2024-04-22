#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <vector>

#include "Algorithms.h"
#include <unistd.h>

typedef enum AlgTypes {
    quicksort,
    insertionSort,
    bubbleSort,
    selectionSort,
    dualPivotQuicksort,
    mergeSort,
    bingoSort,
    pancakeSort,
    combSort,
    gnomeSort
} AlgTypes;

typedef class Algs {
public:
    AlgTypes type;
    double time;
} Algs;

void ViewLeaderboard();
void SortLeaderboard();
void AddToLeaderboard(AlgTypes type, double time);
std::string GetName(AlgTypes type);
void SetupColors();

std::vector<Algs> leaderboard;

int main(int argc, char *argv[]) {
    initscr();

    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    SetupColors();

    int command = ' ';
    while (command != 'Q') {
        clear();
        std::vector<int> arr;
        for (int i = 0; i < getmaxx(stdscr); i++) {
            //(rand() % (upper - lower + 1)) + lower
            arr.push_back((rand() % (getmaxy(stdscr) - 1 + 1)) + 1);
        }

        attron(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);
        mvprintw(0, (getmaxx(stdscr) / 2) - (18 / 2), "SORTING VISUALISER");
        attroff(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);

        mvprintw(4, 0, "Please type the number of the sorting method you would like to see");
        mvprintw(5, 0, "or 'Q' to quit. Type 'L' to view leaderboard.");
        mvprintw(6, 0, "Type 'S' to change delay settings.");

        mvprintw(8, 0, "1. Quicksort");
        mvprintw(9, 0, "2. Insertion Sort");
        mvprintw(10, 0, "3. Bubble Sort");
        mvprintw(11, 0, "4. Selection Sort");
        mvprintw(12, 0, "5. Dual Pivot Quicksort");
        mvprintw(13, 0, "6. Merge Sort");
        mvprintw(14, 0, "7. Bingo Sort");
        mvprintw(15, 0, "8. Pancake Sort");
        mvprintw(16, 0, "9. Comb Sort");
        mvprintw(17, 0, "X. Gnome/Stupid Sort");

        std::chrono::duration<double> seconds;
        mvprintw(20, 0, "Last run: %.2lf seconds.", seconds.count());

        refresh();
        command = getch();

        if (command == 'L') {
            ViewLeaderboard();
        }

        if (command == 'S') {
            clear();
            attron(COLOR_PAIR(COLOR_MAGENTA));
            mvprintw(0, (getmaxx(stdscr) / 2) - (14 / 2), "DELAY SETTINGS");
            attroff(COLOR_PAIR(COLOR_MAGENTA));

            mvprintw(4, 0, "Pick what delay you would like to have. The lower the delay, ");
            mvprintw(5, 0, "the faster the data will sort.");
            mvprintw(6, 0, "(Leaderboard will clear when delay changed.)");

            mvprintw(8, 0, "(1.) Very Fast (0 microseconds)");
            mvprintw(9, 0, "(2.) Fast (10,000 microseconds)");
            mvprintw(10, 0, "(3.) Default (20,000 microseconds)");
            mvprintw(11, 0, "(4.) Slow (30,000 microseconds)");
            mvprintw(12, 0, "(5.) Very Slow (40,000 microseconds)");

            mvprintw(15, 0, "Current delay: %d microseconds", Algorithms::delay);
            mvprintw(getmaxy(stdscr) - 1, 0, "Type q to return.");

            int nextDelay = getch();

            if (nextDelay == 'q')
                continue;

            Algorithms::delay = ((nextDelay - '0') - 1) * 10000;
            leaderboard.clear();
        }

        if (command == '1') {
            QuickSort qs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            qs.Sort(arr, 0, (int)arr.size() - 1);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(quicksort, seconds.count());
            usleep(1750000);
        } else if (command == '2') {
            InsertionSort is;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            is.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(insertionSort, seconds.count());
            usleep(1750000);
        } else if (command == '3') {
            BubbleSort bs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            bs.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(bubbleSort, seconds.count());
            usleep(1750000);
        } else if (command == '4') {
            SelectionSort ss;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            ss.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(selectionSort, seconds.count());
            usleep(1750000);
        } else if (command == '5') {
            DualPivotQuickSort dpqs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            dpqs.Sort(arr, 0, (int)arr.size() - 1);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(dualPivotQuicksort, seconds.count());
            usleep(1750000);
        } else if (command == '6') {
            MergeSort ms;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            ms.Sort(arr, 0, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(mergeSort, seconds.count());
            usleep(1750000);
        } else if (command == '7') {
            BingoSort bs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            bs.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(bingoSort, seconds.count());
            usleep(1750000);
        } else if (command == '8') {
            PancakeSort ps;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            ps.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(pancakeSort, seconds.count());
            usleep(1750000);
        } else if (command == '9') {
            CombSort cs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            cs.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(combSort, seconds.count());
            usleep(1750000);
        } else if (command == 'X') {
            GnomeSort gs;
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            gs.Sort(arr, (int)arr.size());
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            seconds = end - start;
            AddToLeaderboard(gnomeSort, seconds.count());
            usleep(1750000);
        }
    }

    endwin();
    return 0;
}

void ViewLeaderboard() {
    clear();
    attron(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);
    mvprintw(0, (getmaxx(stdscr) / 2) - (11 / 2), "LEADERBOARD");
    attroff(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);

    SortLeaderboard();
    for (int i = 0; i < (int)leaderboard.size(); i++) {
        mvprintw(5 + i, 0, "%d. %s - %.2lf seconds", i + 1, GetName(leaderboard[i].type).c_str(), leaderboard[i].time);
    }

    mvprintw(getmaxy(stdscr) - 1, 0, "Type q to return.");
    refresh();

    while (getch() != 'q')
        ;
}

void SortLeaderboard() {
    int i, j;
    Algs key;
    for (i = 1; i < (int)leaderboard.size(); i++) {
        key = leaderboard[i];
        j = i - 1;

        while (j >= 0 && leaderboard[j].time > key.time) {
            leaderboard[j + 1] = leaderboard[j];
            j = j - 1;
        }
        leaderboard[j + 1] = key;
    }
}

void AddToLeaderboard(AlgTypes type, double time) {
    bool found = false;
    for (int i = 0; i < (int)leaderboard.size(); i++) {
        if (type == leaderboard[i].type) {
            found = true;
            if (time < leaderboard[i].time) {
                leaderboard[i].time = time;
            }
        }
    }
    if (!found) {
        Algs next;
        next.type = type;
        next.time = time;
        leaderboard.push_back(next);
    }
}

std::string GetName(AlgTypes type) {
    switch (type) {
    case 0:
        return "Quicksort";
    case 1:
        return "Insertion Sort";
    case 2:
        return "Bubble Sort";
    case 3:
        return "Selection Sort";
    case 4:
        return "Dual Pivot Quicksort";
    case 5:
        return "Merge Sort";
    case 6:
        return "Bingo Sort";
    case 7:
        return "Pancake Sort";
    case 8:
        return "Comb Sort";
    case 9:
        return "Gnome/Stupid Sort";
    default:
        return "error";
    }
}

void SetupColors() {
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_BLACK, COLOR_WHITE, COLOR_BLACK);
}
