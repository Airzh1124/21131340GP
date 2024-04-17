#include "robotactions.h"
#include "map.h"
#include "playeractions.h"
#include "shipplacement.h"
#include <time.h>

int randomgenerator(int max, int min, int ran){
    srand(time(NULL)+ ran);
    int random = min + (rand() % max);
    return random;
}

void robotplacement(Map &map){
    int Shiplen, Shipwei, Shiprow, Shipcol, Shipnom = 2;
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
            Shipcol = randomgenerator(map.getCols()+1, 0, 1);
            Shiprow = randomgenerator(map.getRows()+1, 0, Shipcol);

        } while (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == true);
        
        placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, 1);
        loopcount++;

        if (loopcount == 5){
            return;
        }
    }
}
