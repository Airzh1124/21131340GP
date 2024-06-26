#include "modes.h"

using namespace std;

void easymode() {
    int maplen, mapwei, count = 0;  //maplen means length of map; mapwei means width of map

    do{
        count++;
        if (count > 1){
            if ((maplen < 8 || maplen > 12)&& (mapwei < 8 || mapwei > 12)){
                information("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 8 || maplen > 12){
                    information("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 8 || mapwei > 12){
                    information("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    information("You can choose the size of the map, from 8*8 to 12*12, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUser("Please enter the length of the map: ");
    mapwei = getUser("Please enter the width of the map: ");
    }while (maplen < 8 || maplen > 12 || mapwei < 8 || mapwei > 12);
    
    Map map1(maplen,mapwei);  //map1 stored the ships placement of the user
    Map map2(maplen,mapwei);  //map2 stored the ships placement of the robots
    Map map3(maplen,mapwei);  //map3 stored the resultant map after user's attack 
    Map map4(maplen,mapwei);  //map4 stored the resultant map after robot's attack, all 4 maps are being modified when performing certain actions

    information("Please wait a moment while our robot prepares the map.");
    
    robotplacement(map2);
    rmcaution();
    int Shipnom = 2, ran = 0;   //Shipnom means Ship number 
    while (Shipshape.empty() == false){
        map1.printDMap();
        getAndplaceShape(map1, Shipnom);
        Shipnom++;
    }
    map1.printDMap();
    refresh();
    rmcaution();
    information("Here is the final version of your map. (Press any key to continue)");
    getch();

    rmcaution();
    information("Press any key to start the attack.");
    refresh();
    getch();
    information("");


    while (true){
        map4.printDMap();
        map1.printCMap();
        vector<int> positions = getPositions(map3);
        //here should have a print out of user's map (meanwhile attracking by robot).
        changeValue(positions, map2, map3);

        if (gameStatus(map2) == true){
        rmcaution();
        instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this game! (press any key to exit)",map1);
        refresh();
        getch();
        rmcaution();
        instruction("Above is the ship placement of the robot (press any key to exit)",map1);
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
        instruction("OHHH NOOOO! The robot have sunk all of your ships, you lost this game! (press any key to exit)",map1);
        refresh();
        getch();
        rmcaution();
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)",map1);
        refresh();
        map2.printDMap();
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
                information("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 13 || maplen > 20){
                    information("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 13 || mapwei > 20){
                    information("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    information("You can choose the size of the map, from 13*13 to 20*20, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUser("Please enter the length of the map: ");
    mapwei = getUser("Please enter the width of the map: ");
    }while (maplen < 13 || maplen > 20 || mapwei < 13 || mapwei > 20);
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    information("Please wait a moment while our robot prepares the map.");
    
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
    information("Here is the final version of your map. (Press any key to continue)");
    getch();

    rmcaution();
    information("Press any key to start the attack.");
    refresh();
    getch();
    information("");


    while (true){
        map4.printDMap();
        map1.printCMap();
        vector<int> positions = getPositions(map3);
        //here should have a print out of user's map (meanwhile attracking by robot).
        changeValue(positions, map2, map3);

        if (gameStatus(map2) == true){
        rmcaution();
        instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this game! (press any key to exit)",map1);
        refresh();
        getch();
        rmcaution();
        instruction("Above is the ship placement of the robot (press any key to exit)",map1);
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
        instruction("OHHH NOOOO! The robot have sunk all of your ships, you lost this game! (press any key to exit)",map1);
        refresh();
        getch();
        rmcaution();
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)",map1);
        refresh();
        map2.printDMap();
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
                information("Sorry, invalid length input and width input of the map");
                refresh();
                getch();
            }
            else{
                if (maplen < 8 || maplen > 20){
                    information("Sorry, invalid length input of the map");
                    refresh();
                }
                if (mapwei < 8 || mapwei > 20){
                    information("Sorry, invalid width input of the map");
                    refresh();
                }
                getch();
            }
        }
    rmcaution();
    information("You can choose the size of the map, from 8*8 to 20*20, the map can be either square or rectangle (press any key to continue).");
    refresh();
    getch();
    maplen = getUser("Please enter the length of the map: ");
    mapwei = getUser("Please enter the width of the map: ");
    }while (maplen < 8 || maplen > 20 || mapwei < 8 || mapwei > 20);
    
    Map map1(maplen,mapwei);
    Map map2(maplen,mapwei);
    Map map3(maplen,mapwei);
    Map map4(maplen,mapwei);

    information("Please wait a moment while our robot prepares the map.");
    
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
    information("Here is the final version of your map. (Press any key to continue)");
    getch();

    information("Press any key to start the attack.");
    refresh();
    getch();
    information("");

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
        instruction("Congratulations! You have sunk all of the opponent's ships! You are the winner of this game! (press any key to exit)",map1);
        refresh();
        getch();
        instruction("Above is the ship placement of the robot (press any key to exit)",map1);
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
        instruction("OHHH NOOOO! The robot have sunk all of your ships, you lost this game! (press any key to exit)",map1);
        refresh();
        getch();
        instruction("Above is the placement for the surviving ship of the robot (press any key to exit)",map1);
        refresh();
        map2.printDMap();
        getch();
        break;
        }
    }

return;
}
