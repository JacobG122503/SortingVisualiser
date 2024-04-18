#include <iostream>
#include <ncurses.h>
#include <vector>

#include "Algorithms.h"
#include <unistd.h>

#define XSIZE 80
#define YSIZE 24

void SetupColors();

int main(int argc, char *argv[]) {
    initscr();
    // Check terminal is correct size before continuing
    int termY, termX;
    getmaxyx(stdscr, termY, termX);
    if (termX != XSIZE || termY != YSIZE) {
        endwin();
        system("clear");
        std::cout << "YOUR TERMINAL SIZE IS CURRENTLY (" << termX << "x" << termY << ")" << std::endl;
        std::cout << "PLEASE SET YOUR TERMINAL SIZE TO " + std::to_string(XSIZE) + "x" + std::to_string(YSIZE) + " AND RE LAUNCH PROGRAM" << std::endl;
        exit(0);
    }
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    SetupColors();

    int command = ' ';
    while (command != 'q') {
        std::vector<int> arr;
        for (int i = 0; i < XSIZE; i++) {
            //(rand() % (upper - lower + 1)) + lower
            arr.push_back((rand() % (YSIZE - 1 + 1)) + 1);
        }

        attron(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);
        mvprintw(0, (XSIZE / 2) - (18 / 2), "SORTING VISUALISER");
        attroff(COLOR_PAIR(COLOR_MAGENTA) | A_BOLD);

        mvprintw(5, 0, "Please type the number of the sorting method you would like to see or q to quit");

        mvprintw(8, 0, "1. Quick Sort");
        mvprintw(9, 0, "2. Insertion Sort");
        mvprintw(10, 0, "3. Bubble Sort");

        refresh();
        command = getch();

        if (command == '1') {
            QuickSort qs;
            qs.Sort(arr, 0, (int)arr.size() - 1);
            usleep(1750000);
            clear();
        } else if (command == '2') {
            InsertionSort is;
            is.Sort(arr, (int)arr.size());
            usleep(1750000);
            clear();
        } else if (command == '3') {
            BubbleSort bs;
            bs.Sort(arr, (int)arr.size());
            usleep(1750000);
            clear();
        }
    }

    endwin();
    return 0;
}

void SetupColors() {
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

