#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include "map.h"

bool isNumber(const string &str);
// check if the input is a number
//Arguments: const string &str: the input

void caution(const string &s);
// print the caution message on the screen
//Arguments: const string &s: the caution message

void rmcaution();
// remove the caution message on the screen

int getUser(const string &prompt);
/*
Arguments:
    const string &prompt: the prompt message
*/
// get the input from user(only number)

int getUserInput(const string &prompt,Map &map);
/*
Arguments:
    const string &prompt: the prompt message
*/
// get the input from user(only number)

void information(const string &s);
/*
Arguments:
    const string &s: the information message
*/
// print the information message on the screen

void instruction(const string &s,Map &map);
/*
Arguments:
    const string &s: the instruction message
    Map &map: the map
*/
// print the instruction on the screen

vector<int> getPositions(Map &map);
// get the input from user and store them
//Arguments: Map &map: the map

void changeValue(vector<int> Postions, Map &map, Map &map1);
// choose a position and change it to chosen status, it will judege wether the player successfully hit the ship.
/*
Arguments:
    vector<int> Postions: the position
    Map &map: the map
    Map &map1: the map
*/
bool gameStatus(Map &map);
// check if the game ends.
//Arguments: Map &map: the map




