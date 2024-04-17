#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "robotactions.h"

using namespace std;

int main() {
    initscr();

    Map map1(10,10);
    Map map2(10,10);
    Map map3(10,10);

    robotplacement(map2);
    while (Shipshape.empty() == false){
        map1.printPMap();
        getAndplaceShape(map1);
    }
    map1.printPMap();
    refresh();
    rmcaution();
    instruction("Here is the final version of your map. (Press any key to continue)");
    getch();

    rmcaution();
    instruction("Press any key to start the attack.");
    refresh();
    getch();


    while (gameStatus(map2) == false)
    {   
        rmcaution();
        map1.printCMap();
        vector<int> positions =  getPositions(map3);
        //here should have a print out of user's map (meanwhile attracking by robot).
        changeValue(positions, map2, map3);
    }
    rmcaution();
    instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this war! (press any key to exit)");

    refresh();
    getch();

    endwin();

    return 0;
}