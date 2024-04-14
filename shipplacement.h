#pragma once

#include "map.h"
#include <iostream>
#include <list>

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
    cout << "{Length, Width}: ";
    for(const auto coordinate: Shipshape){
        int x = coordinate.first;
        int y = coordinate.second;
        cout << "{" << x << ", "<< y << "} ";
    }
    cout << endl;
}
//The purpose of the printShape function is to display the available options for ship shapes.

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

void deleteShape(){
    
}