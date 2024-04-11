#pragma once

#include <iostream>
#include <vector>

char getCell(int x, int y);
/*
Return the character at the given coordinates

Args:
    x (int): x coordinate
    y (int): y coordinate

Returns:
    char: the character at the given coordinates
*/

void setCell(int x, int y, int value);
/*
Set the character at the given coordinates

Args:
    x (int): x coordinate
    y (int): y coordinate
    value (int): the value to set

Representations:
    0 represents empty cell
    1 represents the selected cell
    2 represents the destroyed cell
*/ 

void printMap();
/*
Print the map
by row and column
*/