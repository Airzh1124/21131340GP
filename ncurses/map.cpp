#include "map.h"

//Details of each functions are included in the map.h file 

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

    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    int mapWidth = (grid[0].size() + 1) * 3; 
    int mapHeight = (grid.size() + 1);
    int startX = (terminalWidth - mapWidth) / 2;
    int startY = mapHeight + 2;

    int rownumber = startY + 1;
    
    for (int i = 0; i < grid.size(); i++) {
        mvprintw(rownumber, startX, "%3d ", i);
        for (int j = 0; j < grid[i].size(); j++) {
            mvprintw(startY, startX + (j * 3) + 2, "%3d ", j);
            if (grid[i][j] == 0) {
                mvprintw(rownumber, startX + (j * 3) + 3, " . ");
            } else if (grid[i][j] == 1) {
                mvprintw(rownumber, startX + (j * 3) + 3, " - ");
            } else if (grid[i][j] == 2) {
                mvprintw(rownumber, startX + (j * 3) + 3, " X ");
            }
        }
        rownumber++;
    }
    refresh();
}

void Map::printDMap() {

    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    int mapWidth = (grid[0].size() + 1) * 3; 
    int mapHeight = (grid.size() + 1);
    int startX = (terminalWidth - mapWidth) / 2;
    int startY = mapHeight + 2;

    int rownumber = startY + 1;
    
    for (int i = 0; i < grid.size(); i++) {
        mvprintw(rownumber, startX, "%3d ", i);
        for (int j = 0; j < grid[i].size(); j++) {
            mvprintw(startY, startX + (j * 3) + 2, "%3d ", j);
            if (grid[i][j] == 0) {
                mvprintw(rownumber, startX + (j * 3) + 3, " . ");
            }
            else if (grid[i][j] == 2){
                attron(COLOR_PAIR(1));
                mvprintw(rownumber, startX + (j * 3) + 3, " A ");
                attroff(COLOR_PAIR(1));
            }
            else if (grid[i][j] == 3){
                attron(COLOR_PAIR(2));
                mvprintw(rownumber, startX + (j * 3) + 3, " B ");
                attroff(COLOR_PAIR(2));
            }
            else if (grid[i][j] == 4){
                attron(COLOR_PAIR(3));
                mvprintw(rownumber, startX + (j * 3) + 3, " C ");
                attroff(COLOR_PAIR(3));
            }
            else if (grid[i][j] == 5){
                attron(COLOR_PAIR(4));
                mvprintw(rownumber, startX + (j * 3) + 3, " D ");
                attroff(COLOR_PAIR(4));
            }
            else if (grid[i][j] == 1){
                mvprintw(rownumber, startX + (j * 3) + 3, " X ");
            }
        }
        rownumber++;
    }
    refresh();
}

void Map::printCMap() {

    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    int mapWidth = (grid[0].size() + 1) * 3; 
    int mapHeight = (grid.size() + 1);
    int startX = (terminalWidth - mapWidth) / 2;
    int startY = 0;

    int rownumber = startY + 1;
    
        for (int i = 0; i < grid.size(); i++) {
        mvprintw(rownumber, startX, "%3d ", i);
        for (int j = 0; j < grid[i].size(); j++) {
            mvprintw(startY, startX + (j * 3) + 2, "%3d ", j);
            if (grid[i][j] == 0) {
                mvprintw(rownumber, startX + (j * 3) + 3, " . ");
            }
            else if (grid[i][j] == 2){
                attron(COLOR_PAIR(1));
                mvprintw(rownumber, startX + (j * 3) + 3, " A ");
                attroff(COLOR_PAIR(1));
            }
            else if (grid[i][j] == 3){
                attron(COLOR_PAIR(2));
                mvprintw(rownumber, startX + (j * 3) + 3, " B ");
                attroff(COLOR_PAIR(2));
            }
            else if (grid[i][j] == 4){
                attron(COLOR_PAIR(3));
                mvprintw(rownumber, startX + (j * 3) + 3, " C ");
                attroff(COLOR_PAIR(3));
            }
            else if (grid[i][j] == 5){
                attron(COLOR_PAIR(4));
                mvprintw(rownumber, startX + (j * 3) + 3, " D ");
                attroff(COLOR_PAIR(4));
            }
            else if (grid[i][j] == 1){
                mvprintw(rownumber, startX + (j * 3) + 3, " X ");
            }
        }
        rownumber++;
    }
    refresh();
}
