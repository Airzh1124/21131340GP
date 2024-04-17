#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include "map.h"
using namespace std;

int randomgenerator(int max, int min, int ran);

void robotplacement(Map &map);

void robotattack(Map &map, Map &map1, int &ran);