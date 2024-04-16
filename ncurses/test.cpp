#include <ncurses.h>
#include <string>
#include "playeractions.h"
#include "map.h"

using namespace std;

int main() {
    initscr();
    echo();

    Map map(20,20);
    map.setCell(1, 1, 1);
    map.setCell(2,2,2);
    while (true)
    {
        vector<int> positions =  getPositions(map);
        changeValue(positions, map);
    }
    
    vector<int> positions =  getPositions(map);
    changeValue(positions, map);

    refresh();
    getch();

    endwin();

    return 0;
}