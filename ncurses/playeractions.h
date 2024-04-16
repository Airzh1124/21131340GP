#pragma once

#include <ncurses.h>
#include <vector>
#include map.h

int row;
int col;


void getPositions();
// get the input from user and store them

void changeValue(int row, int col);
// choose a position and change it to chosen status, it will judege wether the player successfully hit the ship.

bool gameStatus(Map &map);
// check if the game ends.




