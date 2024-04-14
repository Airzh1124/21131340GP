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

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    move(max_y - 3, 0);
    clrtoeol();

    printw("Available ship choice are {Length, Width}: ");
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

void getAndplaceShape(Map &map){
    int Shiplen, Shipwei, Shiprow, Shipcol;
    int max_y, max_x;

    echo();
    getmaxyx(stdscr, max_y, max_x);
    printShape();
    move(max_y - 2, 0);
    printw("Please choose one pair from the available set and input numbers only(e.g. 2 3).");
    refresh();
    move(max_y - 1, 0);
    scanf("%d %d", &Shiplen, &Shipwei);
    if (Shapeexist(Shiplen, Shipwei) == true){
        move(max_y - 2, 0);
        clrtoeol();
        printw("Please enter the coordinates of the top-left position where you want to place the ship (e.g. 2 2 (row column)).");
        refresh();
        move(max_y - 1, 0);
        scanf("%d %d", &Shiprow, &Shipcol);
        if (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == false){
            placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, 1);
            deleteShape(Shiplen, Shipwei);
        }
        else{
            move(max_y - 2, 0);
            clrtoeol();
            move(max_y - 1, 0);
            clrtoeol();
            move(max_y - 3, 0);
            printw("Sorry you cannot place here, please try in another cell.");
            refresh();
        }
    }
    else{
        move(max_y - 2, 0);
        clrtoeol();
        move(max_y - 1, 0);
        clrtoeol();
        move(max_y - 3, 0);
        clrtoeol();
        printw("Sorry, the shape you entered is not in the list, please try again.");
        refresh();
    }
}