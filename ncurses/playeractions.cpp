#pragma once

#include <ncurses.h>
#include <vector>
#include map.h

int row;
int col;

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


void getPositions(Map &map){
  bool a = false;
  while ( a == false ){
    instruction("Please enter the chosen x position: ");
    refresh();
    int row = getch();
    instruction("Please enter the chosen y position: ");
    refresh();
    int col = getch();
    if (row >= 0 && row < map.getCols() && col >= 0 && col < map.getRows()){
      if (map.getCell(row, col) != 1){
        a = true;
      }
    }
    else{
      instruction("Invalid input, please try again");
        }
    }
}



void changeValue(int row, int col){
  int value = map.getCell(row, col);
  if (value == 0){
    instruction("Oops! You miss the shot!")
    map.setCell(row, col, 1);
  }
  else{
    instruction("Congratulations! you hit one ship successfully! ");
    for (int i = 0; i < map.getCols(); i++){
      for (int j = 0; j < map.getRows(); j++){
        if (map.getCell(i, j) == value){
          map.setCell(row, col, 1)
        }
      }
    }

    
  }

  
}

bool gameStatus(Map &map){
  int number = 0;
  bool game = false;
  for (int i = 0; i < map.getCols(); i++){
      for (int j = 0; j < map.getRows(); j++){
        if (map.getCell(i, j) == 2 || map.getCell(i, j) == 3 || map.getCell(i, j) == 4 || map.getCell(i, j) == 5){
          number = number + 1;
        }
      }
  }
  if (number == 0){
    game = true
  }
  return game;
}









