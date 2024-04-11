#include "map.h"

using namespace std;

class Map {
private:
    vector<vector<int> > grid;

public:
    Map(int rows, int cols) : grid(rows, vector<int>(cols, 0)) {}

    int getCell(int x, int y) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            return grid[x][y];
        }
        return ' ';
    }

    void setCell(int x, int y, int value) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            grid[x][y] = value;
        }
    }

    void printMap() {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0){
                    cout << "O ";
                }else{
                    cout << "X ";
                }
            }   
            cout << endl;
        }
    }
};