#include "robotactions.h"

int randomgenerator(int max, int min, int ran){
    srand(time(NULL)+ ran);
    int random = min + (rand() % max);
    return random;
}

void robotplacement(Map &map){
    int Shiplen, Shipwei, Shiprow, Shipcol, Shipnom = 2, ran = 0;
    int max_y, max_x, loopcount = 0;
    getmaxyx(stdscr, max_y, max_x);
    for (const auto& pair: Shipshape){
        if (randomgenerator(2, 0, 1) == 1){
            Shiplen = pair.first;
            Shipwei = pair.second;
        }
        else if (randomgenerator(2, 0, 1) == 0){
            Shiplen = pair.second;
            Shipwei = pair.first;
        }

        do{
            ran++;
            Shipcol = randomgenerator(map.getCols()+1, 0, ran);
            Shiprow = randomgenerator(map.getRows()+1, 0, Shipcol);

        } while (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == true);
        
        placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, Shipnom);
        Shipnom++;
        loopcount++;

        if (loopcount == 5){
            return;
        }
    }
}

void robotattack(Map &map, Map &map1, int &ran){
    int Shipcol, Shiprow;
    do{
        ran++;
        Shipcol = randomgenerator(map.getCols()+1, 0, ran);
        Shiprow = randomgenerator(map.getRows()+1, 0, Shipcol);
    }while (map1.getCell(Shiprow, Shipcol) != 0);
    int value = map.getCell(Shiprow, Shipcol);

    if (value == 0){
        map1.setCell(Shiprow, Shipcol, 1);
        map.setCell(Shiprow, Shipcol, 1);
        map1.printDMap();
    }
    else{
        for (int i = 0; i < map.getCols(); i++){
            for (int j = 0; j < map.getRows(); j++){
                if (map.getCell(i, j) == value){
                    map1.setCell(i, j, value);
                    map.setCell(i, j, 1);
                    map1.printDMap();
                }
            }
        }
    }
    instruction("The robot had randomly attacked this coordinate: ");
    printw("%d %d", Shiprow, Shipcol);
    return;
}