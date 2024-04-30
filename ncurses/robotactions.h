#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include "map.h"
#include "robotactions.h"
#include "playeractions.h"
#include "shipplacement.h"
#include <time.h>
using namespace std;

int randomgenerator(int max, int min, int ran);
// generate a random number
/*
Arguments:
    int max: the maximum number
    int min: the minimum number
    int ran: the random number
*/

void robotplacement(Map &map);
// place the robot's ships
//Arguments: Map &map: the map

void robotattack(Map &map, Map &map1, int &ran);
// the robot attacks the player's map
/*
Arguments:
    Map &map: the map
    Map &map1: the map
    int &ran: the random number
*/