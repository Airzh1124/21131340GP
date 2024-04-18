#include "robotactions.h"
#include "map.h"
#include "playeractions.h"
#include "shipplacement.h"
#include <time.h>
#include <random>


using namespace std;

int randomgenerator(int max, int min, int ran){
    srand(time(NULL)+ ran);
    int random = min + (rand() % max);
    return random;
}

void instruction(const string &s) {
    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    for (int i = 1; i <= 4; i++) {
        move(terminalHeight - i, 0);
        clrtoeol();
    }

    move(terminalHeight - 4, 0);
    
    const char *cstr = s.c_str();
    printw("%s", cstr);
    refresh();
}

void masterRobotattack(Map &map, Map &map1, int &ran){
    vector<vector<int>> targets;
    for (int i = 0; i < map.getCols(); i++){
            for (int j = 0; j < map.getRows(); j++){
              if (map.getCell(i,j) != 0 && map.getCell(i,j) != 1){ //找出所有存有船只的位置，并以vector形式存储
                vector<int> a = {i, j}
                targets.push_back(a)
              } 
            }
    }
    int chosen = randomgenerator(0, targets.size() - 1, ran); //作弊选中一个vector
    int i = targets[chosen][0]
    int j = targets[chosen][1]
    int value = map.getCell(i, j);
    for (int i = 0; i < map.getCols(); i++){
            for (int j = 0; j < map.getRows(); j++){
                if (map.getCell(i, j) == value){
                    map1.setCell(i, j, value);
                    map.setCell(i, j, 1);
                    map1.printDMap();
                }
            }
        }
    instruction("The robot had attacked the coordinate: ");
    printw("%d %d", Shiprow, Shipcol);
    return;
  }
}
