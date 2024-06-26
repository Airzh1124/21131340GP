#include <iostream>
#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "egg.h"
#include "robotactions.h"
#include "Starting_screen.h"
#include "modes.h"
#include "masterMode.h"

int main() {
    initscr();
    curs_set(0);
    keypad(stdscr, false); //unables the interpretation of function keys as special control sequences

    if (has_colors() == false){
        information("Sorry, your computer does not support colour, but you could still enjoy the black & white version of the game :)");
        getch();
        return 0;
    }
    start_color();      //Giving each sets of boats their unique colours
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    Print_map(ship);
    refresh();


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);    //Getting the size of the user's window 

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
                mvwprintw(menuwin, i + 1, 1, choices[i].c_str());     //User's meun selection
                wattroff(menuwin, A_REVERSE);
            } else {
                mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            }
        }
        choice = wgetch(menuwin);

        switch(choice) {
            case KEY_UP:
                if (highlight > 0) highlight--;    //User's selecting the former or latter choice in the menu 
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

    while (true){                //Opening the corresponding mode
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
    information("Wish to see you again soon, have a nice dayyy :)");
    refresh();
    getch();

    endwin();
    return 0;
}
