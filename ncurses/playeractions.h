#pragma once

#include <ncurses.h>
#include <vector>
#include map.h

int row;
int col;


void getPositions();
// get the input from user and store them

int choosePosition(int row, int col);
// choose a position and check which integer it is, if it is a nonzero number, the delete it from the map.

bool gameStatus(Map &map);
// check if the map still contain any nonzero number, if over, return true.

void shipSink(Map &map, int shipNumber);
// change the ship to the sink status




