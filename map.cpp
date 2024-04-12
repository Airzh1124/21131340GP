#include "map.h"

using namespace std;

class Map {
private:
    vector<vector<int> > grid;

public:
    Map(int rows, int cols) : grid(rows, vector<int>(cols, 0)) {}

    int getRows() {
        return grid.size();
    }

    int getCols() {
        return grid[0].size();
    }

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

    void printPMap() {
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

    void printCMap() {
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
};

int main() {
    Map map(20,20);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == j)
            {
                map.setCell(i, j, 1);
            }
            if (i > j)
            {
                map.setCell(i, j, 2);
            }
            
        }
    }
    map.printPMap();
    map.printCMap();
    return 0;
}