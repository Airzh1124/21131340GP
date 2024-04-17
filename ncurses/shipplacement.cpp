#include "shipplacement.h"


list<pair<int, int> > Shipshape = {make_pair(2, 2), make_pair(2, 3), make_pair(2, 4), make_pair(3, 5)};

void placeShip(Map &map, int row, int cols, int Shiplen, int Shipwei, int ShipNom){
    for (int i = row; i < row + Shiplen; i++){
        for (int j = cols; j < cols + Shipwei; j++){
            map.setCell(i, j, ShipNom);
        }
    }
}

bool overlap(Map &map, int row, int cols, int Shiplen, int Shipwei){
    for (int i = row; i < row + Shiplen; i++){
        for (int j = cols; j < cols + Shipwei; j++){
            if (map.getCell(i, j) != 0){
                return true;
            }
        }
    }
    return false;
}

void printShape(){

    caution("Available ship choice are {Length, Width}: ");
    for(const auto coordinate: Shipshape){
        int x = coordinate.first;
        int y = coordinate.second;
        printw("{%d, %d} ", x, y);
    }
    refresh();
}

bool Shapeexist(int Shiplen, int Shipwei){
    for (const auto coordinate: Shipshape){
        int x = coordinate.first;
        int y = coordinate.second;
        if ((x == Shiplen && y == Shipwei) | (y == Shiplen && x == Shipwei)){
            return true;
        }
    }
    return false;
}

void deleteShape(int Shiplen, int Shipwei){
    for (const auto coordinate: Shipshape){
        int x = coordinate.first;
        int y = coordinate.second;
        if ((x == Shiplen && y == Shipwei) | (y == Shiplen && x == Shipwei)){
            if (x == Shiplen && y == Shipwei){
                Shipshape.remove(make_pair(Shiplen, Shipwei));
            }
            else{
                Shipshape.remove(make_pair(Shipwei, Shiplen));
            }
            return;
        }
    }
}

void getAndplaceShape(Map &map, int Shipnom){
    int Shiplen, Shipwei, Shiprow, Shipcol;
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    printShape();
    Shiplen = getUserInput("Please enter the length of the ship: ");
    Shipwei = getUserInput("Please enter the width of the ship: ");
    if (Shapeexist(Shiplen, Shipwei) == true){
        Shiprow = getUserInput("Please enter the chosen x position: ");
        Shipcol = getUserInput("Please enter the chosen y position: ");
        if (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == false){
            placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, Shipnom);
            deleteShape(Shiplen, Shipwei);
            printShape();
        }
        else{
            instruction("Sorry you cannot place here, please try in another cell.(Press any key to continue)");
            getch();
        }
    }
    else{
        instruction("Sorry, the shape you entered is not in the list, please try again.(Press any key to continue)");
        getch();
    }
}