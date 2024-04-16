#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include "map.h"

bool isNumber(const string &str);
// check if the input is a number

void caution(const string &s);
// print the caution message on the screen

void rmcaution();
// remove the caution message on the screen

int getUserInput(const string &prompt);
/*
Arguments:
    const string &prompt: the prompt message
*/
// get the input from user(only number)

void instruction(const string &s);
/*
Arguments:
    const string &s: the instruction message
*/
// print the instruction on the screen

vector<int> getPositions(Map &map);
// get the input from user and store them

void changeValue(vector<int> Postions, Map &map);
// choose a position and change it to chosen status, it will judege wether the player successfully hit the ship.

bool gameStatus(Map &map);
// check if the game ends.




