#pragma once

#include "map.h"
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

extern list<pair<int, int> > Shipshape;

void placeShip(Map &map, int row, int cols, int Shiplen, int Shipwei, int ShipNom);
//To place the ship in predetermined cells.

bool overlap(Map &map, int row, int cols, int Shiplen, int Shipwei);
//To check whether the ship will overlap with other ships before placing it.

void printShape();
//The purpose of the printShape function is to display the available options for ship shapes.

bool Shapeexist(int Shiplen, int Shipwei);
//Checking whether the entered shape is available or not by comparing the entered pair with pairs in the list.

void deleteShape(int Shiplen, int Shipwei);
//Delete the shape pair from the list after the user has already placed it.

void getAndplaceShape(Map &map);
