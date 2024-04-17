#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "robotactions.h"
using namespace std;

int main(){
    initscr();
    Map map2(20,20);
    refresh();

    robotplacement(map2);
    map2.printCMap();
    getch();

endwin();

return 0;
}