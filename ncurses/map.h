#pragma once

#include <ncurses.h>
#include <vector>

using namespace std;

class Map {
private:
    vector<vector<int> > grid;

public:
    Map(int rows, int cols);
    /*
    Constructor of the Map class
    */
    int getRows();
    /*
    Return the number of rows in the map
    */

    int getCols();
    /*
    Return the number of columns in the map
    */

    int getCell(int x, int y);
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

    void printPMap();
    /*
    Print the map of the player
    */

    void printDMap();

    void printCMap();
    /*
    Print the map of the computer
    */
};