#include "modes.h"

using namespace std;

void easymode() {
    int maplen, mapwei, count = 0;

    do{
        count++;
        if (count > 1){
            if ((maplen < 8 || maplen > 12)&& (mapwei < 8 || mapwei > 12)){
                instruction("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 8 || maplen > 12){
                    instruction("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 8 || mapwei > 12){
                    instruction("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    instruction("You can choose the size of the map, from 8*8 to 12*12, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUserInput("Please enter the length of the map: ");
    mapwei = getUserInput("Please enter the width of the map: ");
    }while (maplen < 8 || maplen > 12 || mapwei < 8 || mapwei > 12);
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    instruction("Please wait a moment while our robot prepares the map.");
    
    robotplacement(map2);
    rmcaution();
    int Shipnom = 2, ran = 0;
    while (Shipshape.empty() == false){
        map1.printDMap();
        getAndplaceShape(map1, Shipnom);
        Shipnom++;
    }
    map1.printDMap();
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
        map2.printDMap();
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
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)");
        refresh();
        map2.printDMap();
        map4.printDMap();
        getch();
        break;
        }
    }

return;
}

void hardmode() {
    int maplen, mapwei, count = 0;

    do{
        count++;
        if (count > 1){
            if ((maplen < 13 || maplen > 20)&& (mapwei < 13 || mapwei > 20)){
                instruction("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 13 || maplen > 20){
                    instruction("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 13 || mapwei > 20){
                    instruction("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    instruction("You can choose the size of the map, from 13*13 to 20*20, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUserInput("Please enter the length of the map: ");
    mapwei = getUserInput("Please enter the width of the map: ");
    }while (maplen < 13 || maplen > 20 || mapwei < 13 || mapwei > 20);
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    instruction("Please wait a moment while our robot prepares the map.");
    
    robotplacement(map2);
    rmcaution();
    int Shipnom = 2, ran = 0;
    while (Shipshape.empty() == false){
        map1.printDMap();
        getAndplaceShape(map1, Shipnom);
        Shipnom++;
    }
    map1.printDMap();
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
        map2.printDMap();
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
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)");
        refresh();
        map2.printDMap();
        map4.printDMap();
        getch();
        break;
        }
    }

return;
}

void mastermode() {
    int maplen, mapwei, count = 0;

    do{
        count++;
        if (count > 1){
            if ((maplen < 8 || maplen > 20)&& (mapwei < 8 || mapwei > 20)){
                instruction("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 8 || maplen > 20){
                    instruction("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 8 || mapwei > 20){
                    instruction("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    instruction("You can choose the size of the map, from 8*8 to 20*20, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUserInput("Please enter the length of the map: ");
    mapwei = getUserInput("Please enter the width of the map: ");
    }while (maplen < 8 || maplen > 20 || mapwei < 8 || mapwei > 20);
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    instruction("Please wait a moment while our robot prepares the map.");
    
    robotplacement(map2);
    rmcaution();
    int Shipnom = 2, ran = 0;
    while (Shipshape.empty() == false){
        map1.printDMap();
        getAndplaceShape(map1, Shipnom);
        Shipnom++;
    }

    map1.printDMap();
    refresh();
    rmcaution();
    instruction("Here is the final version of your map. (Press any key to continue)");
    getch();

    rmcaution();
    instruction("Press any key to start the attack.");
    refresh();
    getch();

    int gamecount = 1;
    while (true){
        map4.printDMap();
        map1.printCMap();
        vector<int> positions = getPositions(map3);
        //here should have a print out of user's map (meanwhile attracking by robot).
        changeValue(positions, map2, map3);

        if (gameStatus(map2) == true){
        egg();
        rmcaution();
        instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this game! (press any key to exit)");
        refresh();
        getch();
        rmcaution();
        instruction("Above is the ship placement of the robot (press any key to exit)");
        refresh();
        map2.printDMap();
        getch();
        break;
        }

        if (gamecount % 3 == 0){
            masterRobotattack(map1, map4, ran);
        }
        else {
            robotattack(map1, map4, ran);
        }
        gamecount++;
        map4.printDMap();
        getch();//maybe some instruction? or diaplaying the map4 continuously
        
        if (gameStatus(map1) == true){
        egg();
        rmcaution();
        instruction("OHHH NOOOO! The robot have sunk all of your ships, you lost this game! (press any key to exit)");
        refresh();
        getch();
        rmcaution();
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)");
        refresh();
        map2.printCMap();
        map4.printDMap();
        getch();
        break;
        }
    }

return;
}