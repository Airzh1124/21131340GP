#include <iostream>
#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "robotactions.h"
#include "Starting_screen.h"
#include "modes.h"
#include "masterMode.h"

int main() {
    initscr();
    curs_set(0);

    Print_map(ship);
    refresh();


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * menuwin = newwin(6, xMax - 12, yMax -8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);


     string choices[4] = {"1. Easy Mode", "2. Difficult Mode", "3. Expert Mode", "4. Quit"};
     int choice;
     int highlight = 0;

     while (true) {
        for (int i = 0; i < 4; i ++) {
            if (i == highlight) {
                wattron(menuwin, A_REVERSE);
                mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
                wattroff(menuwin, A_REVERSE);
            } else {
                mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            }
        }
        choice = wgetch(menuwin);

        switch(choice) {
            case KEY_UP:
                if (highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < 3) highlight++;
                break;
            default:
                break;
        }
        if (choice == 10) { // Enter key
            break;
        }
    }
    clear();
    rmcaution();
    int n = highlight + 1;

    while (true){
        if (n == 4){
            break;
        }
        else{
            if (n == 1){
                easymode();
                break;
            }
            if (n == 2){
                hardmode();
                break;
            }
            if (n == 3){
                mastermode();
                break;
            }
        }
    }
    //maybe ending animation or ending words here
    instruction("Wish to see you again soon, have a nice dayyy :)");
    refresh();
    getch();

    endwin();
    return 0;
}