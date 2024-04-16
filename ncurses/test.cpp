#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"

using namespace std;

int main() {
    initscr();

    Map map1(20,20);
    Map map2(20,20);

    while (Shipshape.empty() == false){
        map1.printPMap();
        getAndplaceShape(map1);
    }

    rmcaution();

    while (true)
    {
        vector<int> positions =  getPositions(map2);
        changeValue(positions, map2);
    }

    refresh();
    getch();

    endwin();

    return 0;
}