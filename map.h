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

void setCell(int x, int y, char value);
/*
Set the character at the given coordinates

Args:
    x (int): x coordinate
    y (int): y coordinate
    value (char): the character to set
*/ 
void printMap();
/*
Print the map
*/