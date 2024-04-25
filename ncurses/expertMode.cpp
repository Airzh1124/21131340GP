#include "expertMode.h"

void masterRobotattack(Map &map1, Map &map4, int &ran){
    vector<vector<int>> targets;
    for (int i = 0; i < map1.getCols(); i++){
            for (int j = 0; j < map1.getRows(); j++){
              if (map1.getCell(i,j) != 0 && map1.getCell(i,j) != 1){ //找出所有存有船只的位置，并以vector形式存储
                vector<int> a = {i, j};
                targets.push_back(a);
              } 
            }
    }
    int chosen = randomgenerator(targets.size(), 0, ran); //作弊选中一个vector
    int x = targets[chosen][0];
    int y = targets[chosen][1];
    int value = map1.getCell(x, y);
    for (int i = 0; i < map1.getCols(); i++){
            for (int j = 0; j < map1.getRows(); j++){
                if (map.getCell(i, j) == value){
                    map4.setCell(i, j, value);
                    map1.setCell(i, j, 1);
                    map4.printDMap();
                }
            }
        }
    instruction("The robot had activated its skill and attacked this coordinate: ");
    printw("%d %d", x, y);
    return;
}
