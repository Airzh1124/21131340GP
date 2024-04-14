#include "map.h"
#include "shipplacement.h"
#include <ncurses.h>
#include <signal.h>

int main(){
    int x, y, value, placementcout = 0, Shiplen, Shipwei, Shiprow, Shipcol;
    int max_y, max_x;

    initscr(); 
    keypad(stdscr, TRUE);
    echo(); 

    scanf("%d %d", &x, &y);
    Map m1(x, y);

    while (Shipshape.empty() == false) {
        clear();
        m1.printCMap();
        m1.printPMap();
        getAndplaceShape(m1);

    }

    endwin();
    return 0;
}