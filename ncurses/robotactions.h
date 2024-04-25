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

void robotplacement(Map &map);

void robotattack(Map &map, Map &map1, int &ran);