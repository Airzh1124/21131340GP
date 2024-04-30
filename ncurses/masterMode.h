#include "robotactions.h"
#include "map.h"
#include "playeractions.h"
#include "shipplacement.h"
#include <time.h>
#include <random>

void masterRobotattack(Map &map, Map &map1, int &ran);
// the robot attacks the player's map
/*
Arguments:
    Map &map: the map
    Map &map1: the map
    int &ran: the random number
*/
