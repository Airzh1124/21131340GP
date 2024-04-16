#pragma once

#include <ncurses.h>
#include <vector>
#include map.h

int row;
int col;


void getPositions(Map &map){
  bool a = false;
  while ( a == false ){
    mvprintw("Please enter the chosen x position: ");
    refresh();
    int row = getch();
    mvprintw("Please enter the chosen y position: ");
    refresh();
    int col = getch();
    if (row >= 0 && row < map.getCols() && col >= 0 && col < map.getRows()){
      if (map.getCell(row, col) != 1){
        a = true;
      }
    }
    else{
      mvprintw("Invalid input, please try again");
    }
}



void changeValue(int row, int col){
  int value = map.getCell(row, col);
  if (value == 0){
    mvprintw("Oops! You miss the shot!")
    map.setCell(row, col, 1);
  }
  else{
    mvprintw("Congratulations! you hit one ship successfully! ");
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









