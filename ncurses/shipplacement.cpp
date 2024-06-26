#include "shipplacement.h"


list<pair<int, int> > Shipshape = {make_pair(3, 5), make_pair(2, 4), make_pair(2, 3), make_pair(2, 2)};

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
    do{
        printShape();
        Shiplen = getUser("Please enter the length of the ship: ");
        Shipwei = getUser("Please enter the width of the ship: ");

        if (Shapeexist(Shiplen, Shipwei) == false){
            information("Sorry, the shape you entered is not in the list, please try again.(Press any key to continue)");
            getch();
        }

    }while (Shapeexist(Shiplen, Shipwei) == false);

    do{
        Shiprow = getUser("Please enter the chosen x position: ");
        Shipcol = getUser("Please enter the chosen y position: ");

        if (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == true){
            information("Sorry you cannot place here, please try in another cell.(Press any key to continue)");
            getch();
        }

    }while(overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == true);


    placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, Shipnom);
    deleteShape(Shiplen, Shipwei);
    printShape();
    
return;
}