#pragma once

#include "map.h"
#include "playeractions.h"
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

extern list<pair<int, int> > Shipshape;

void placeShip(Map &map, int row, int cols, int Shiplen, int Shipwei, int ShipNom);
//To place the ship in predetermined cells.
/*
Args:
    Map &map: the map
    int row: the row
    int cols: the column
    int Shiplen: the length of the ship
    int Shipwei: the width of the ship
    int ShipNom: the ship number
*/

bool overlap(Map &map, int row, int cols, int Shiplen, int Shipwei);
//To check whether the ship will overlap with other ships before placing it.
/*
Args:
    Map &map: the map
    int row: the row
    int cols: the column
    int Shiplen: the length of the ship
    int Shipwei: the width of the ship
*/

void printShape();
//The purpose of the printShape function is to display the available options for ship shapes.

bool Shapeexist(int Shiplen, int Shipwei);
//Checking whether the entered shape is available or not by comparing the entered pair with pairs in the list.
/*
Args:
    int Shiplen: the length of the ship
    int Shipwei: the width of the ship
*/
void deleteShape(int Shiplen, int Shipwei);
//Delete the shape pair from the list after the user has already placed it.
/*
Args:
    int Shiplen: the length of the ship
    int Shipwei: the width of the ship
*/

void getAndplaceShape(Map &map, int Shipnom);
//To get the shape and place it in the map.
/*
Args:
    Map &map: the map
    int Shipnom: the ship number
*/
