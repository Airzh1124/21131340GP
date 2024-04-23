#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "robotactions.h"

using namespace std;

int main() {
    initscr();

    int maplen = getUserInput("Please enter the length of the map: ");
    int mapwei = getUserInput("Please enter the width of the map: ");
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    instruction("Please wait a moment while our robot prepares the map.");
    
    robotplacement(map2);
    rmcaution();
    int Shipnom = 2, ran = 0;
    while (Shipshape.empty() == false){
        map1.printCMap();
        getAndplaceShape(map1, Shipnom);
        Shipnom++;
    }
    map1.printCMap();
    refresh();
    rmcaution();
    instruction("Here is the final version of your map. (Press any key to continue)");
    getch();

    rmcaution();
    instruction("Press any key to start the attack.");
    refresh();
    getch();


    while (true){
        map4.printDMap();
        map1.printCMap();
        vector<int> positions = getPositions(map3);
        //here should have a print out of user's map (meanwhile attracking by robot).
        changeValue(positions, map2, map3);

        if (gameStatus(map2) == true){
        rmcaution();
        instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this game! (press any key to exit)");
        refresh();
        getch();
        rmcaution();
        instruction("Above is the ship placement of the robot (press any key to exit)");
        refresh();
        map2.printCMap();
        getch();
        break;
        }

        robotattack(map1, map4, ran);
        map4.printDMap();
        getch();//maybe some instruction? or diaplaying the map4 continuously
        
        if (gameStatus(map1) == true){
        rmcaution();
        instruction("OHHH NOOOO! The robot have sunk all of your ships, you lost this game! (press any key to exit)");
        refresh();
        getch();
        rmcaution();
        instruction("Above is the ship placement of the robot (press any key to exit)");
        refresh();
        map2.printCMap();
        map4.printDMap();
        getch();
        break;
        }
    }

    endwin();

    return 0;
}