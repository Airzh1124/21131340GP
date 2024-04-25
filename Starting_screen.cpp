#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>
using namespace std;


const vector<string> ship = {
    "                                                                                                    ",
    "      +------------------------------------------------------------+                                ",
    "      | _____ _   _  ____  ____ _ _____ _  _    ___     ____ ____  |                                ",
    "      || ____| \\ | |/ ___|/ ___/ |___ /| || |  / _ \\   / ___|  _ \\ |                             ",
    "      ||  _| |  \\| | |  _| |  _| | |_ \\| || |_| | | | | |  _| |_) ||                              ",
    "      || |___| |\\  | |_| | |_| | |___) |__   _| |_| | | |_| |  __/ |                               ",
    "      ||_____|_| \\_|\\____|\\____|_|____/   |_|  \\___/   \\____|_|    |                           ",
    "      +------------------------------------------------------------+                                ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                            (%  .                                   ",
    "                                                         *@@@, /                                    ",
    "                                                  #       @@.% *                                    ",
    "                                                  &     (@@&.&,*                                    ",
    "                                               ,  (@@@@@.&*@@@@#                                    ",
    "      #                                        @@%(@@@@@@%  /&@@.                                   ",
    "      #                                @@@@@@@@@@@@@@@@@@@@@@@@//                         .         ",
    "      #                #@@.&@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@,                        ,         ",
    "      #                 ,@@@@@@@@@@@@@((@@@@@@@@@@@@@@@@@@@@@@@@@@@..,*                   ,         ",
    "      #  ,    #  %      @@@@@@@@@@@@@@(*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&            /%%.        ",
    "      @( ( ,  %, # * *@ (@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @,         ",
    "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      ",
    "       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  ", 
    "         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ",
    "           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ",
    "             &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&  ",
    "               %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%%%%%%%%%%%%%  ",
    "                 *         +@@@@@@@@@%%%%%%%%%#########********************************************+:",

};






void Print_map(const vector<string>& art) {
    for (int i = 0; i < art.size(); i++) {
        mvprintw(5 + i, 10, "%s", art[i].c_str());  // Print each line at increasing y position
    }
}

int main() {
    initscr();
    noecho();
    cbreak(); 

    Print_map(ship);
    refresh();


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * menuwin = newwin(6, xMax - 12, yMax -8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);


     string choices[3] = {"1. Easy Mode", "2. Difficult Mode", "3. Quit"};
     int choice;
     int highlight = 0;

     while (true) {
        for (int i = 0; i < 3; i ++) {
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
                if (highlight < 2) highlight++;
                break;
            default:
                break;
        }
        if (choice == 10) { // Enter key
            break;
        }
    }
    endwin();
    return 0;
}