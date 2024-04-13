#include "map.h"

Map::Map(int rows, int cols) : grid(rows, vector<int>(cols, 0)) {}

int Map::getRows() {
    return grid.size();
}

int Map::getCols() {
    return Map::grid[0].size();
}

int Map::getCell(int x, int y) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        return grid[x][y];
    }
    return ' ';
}

void Map::setCell(int x, int y, int value) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        grid[x][y] = value;
    }
}

void Map::printPMap() {
    cout << setw(2) << " " << " ";
    for (int j = 0; j < grid[0].size(); ++j) {
        cout << setw(2) << j << " ";
    }
    cout << endl;
    int rownumber = 0;
    for (int i = 0; i < grid.size(); i++) {
        cout << setw(2) <<rownumber++ << " ";
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 0){
                cout << setw(2) << "." << " ";
            }
            if (grid[i][j] == 1){
                cout << setw(2) << "-" << " ";
            }
            if (grid[i][j] == 2){
                cout << setw(2) << "X" << " ";
            }
        }   
        cout << endl;
    }
}

void Map::printCMap() {
    cout << setw(2) << " " << " " ;
    for (int j = 0; j < grid[0].size(); ++j) {
        cout << setw(2) << j << " ";
    }
    cout << endl;
    int rownumber = 0;
    for (int i = 0; i < grid.size(); i++) {
        cout << setw(2) << rownumber++ << " ";
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 0){
                cout << setw(2) << "." << " ";
            }else{
                cout << setw(2) << "X" << " ";
            }
        }   
        cout << endl;
    }
}