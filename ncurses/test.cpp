#include <iostream>
#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"
#include "shipplacement.h"
#include "robotactions.h"
#include "Starting_screen.h"
#include "modes.h"
#include "masterMode.h"

using namespace std;

int main(){
    initscr();
    curs_set(0);
    Map map(8, 8);

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
            map.printDMap();
            Shipnom++;
            loopcount++;

            if (loopcount == 5){
                break;
            }
        }

    getch();
endwin();
return 0;
}