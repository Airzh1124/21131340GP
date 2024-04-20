#include "expertMode.h"

void masterRobotattack(Map &map, Map &map1, int &ran){
    vector<vector<int>> targets;
    for (int i = 0; i < map.getCols(); i++){
            for (int j = 0; j < map.getRows(); j++){
              if (map.getCell(i,j) != 0 && map.getCell(i,j) != 1){ //找出所有存有船只的位置，并以vector形式存储
                vector<int> a = {i, j};
                targets.push_back(a);
              } 
            }
    }
    int chosen = randomgenerator(targets.size(), 0, ran); //作弊选中一个vector
    int i = targets[chosen][0];
    int j = targets[chosen][1];
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
    instruction("The robot had activated its skill and attacked this coordinate: ");
    printw("%d %d", i, j);
    return;
}
