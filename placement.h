#pragma once

#include <iostream>
using namespace std;

void placeShip(Map &map, int row, int cols, int Shiplen, int Shipwei, int ShipNom){
    for (int i = row; i < row + Shiplen; i++){
        for (int j = cols; j < cols + Shipwei; j++){
            map.setCell(i, j, ShipNom);
        }
    }
}
