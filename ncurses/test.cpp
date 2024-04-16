#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"

using namespace std;

int main() {
    initscr();

    Map map(20,20);

    while (Shipshape.empty() == false){
        map.printPMap();
        getAndplaceShape(map);
    }

    rmcaution();

    while (true)
    {
        vector<int> positions =  getPositions(map);
        changeValue(positions, map);
    }
    
    vector<int> positions =  getPositions(map);
    changeValue(positions, map);

    refresh();
    getch();

    endwin();

    return 0;
}