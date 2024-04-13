#pragma once

#include <iostream>
using namespace std;

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