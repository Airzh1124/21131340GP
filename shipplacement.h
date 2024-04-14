#pragma once

#include "map.h"
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

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
    cout << '\n' << "Available ship choice are {Length, Width}: ";
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
    printShape();
    cout << "Please choose one pair from the available set and input numbers only(e.g. 2 3)." << endl;
    cin >> Shiplen >> Shipwei;
    if (Shapeexist(Shiplen, Shipwei) == true){
        cout << "Please enter the coordinates of the top-left position where you want to place the ship (e.g. 2 2 (row column))." << endl;
        cin >> Shiprow >> Shipcol;
        if (overlap(map, Shiprow, Shipcol, Shiplen, Shipwei) == false){
            placeShip(map, Shiprow, Shipcol, Shiplen, Shipwei, 1);
            deleteShape(Shiplen, Shipwei);
        }
        else{
            cout << '\n' << "Sorry you cannot place here, please try in another cell." << '\n' << endl;
        }
    }
    else{
        cout << '\n' << "Sorry, the shape you entered is not in the list, please try again." << endl;
    }
}