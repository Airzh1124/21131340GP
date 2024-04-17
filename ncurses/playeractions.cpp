#include "playeractions.h"

bool isNumber(const string &str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void caution(const string &s) {
    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    move(terminalHeight - 5, 0);
    clrtoeol();

    const char *cstr = s.c_str();
    printw("%s", cstr);
    refresh();
}

void rmcaution() {
    int terminalWidth, terminalHeight;
    getmaxyx(stdscr, terminalHeight, terminalWidth);

    move(terminalHeight - 5, 0);

    clrtoeol();
    refresh();
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

int getUserInput(const string &prompt) {
    string input;
    
    do {
        instruction(prompt);
        refresh();

        char inputBuffer[100];
        getstr(inputBuffer);
        input = inputBuffer;

        if (!isNumber(input)) {
            instruction("Invalid input. Please try again. (Press any key to continue)");
            getch();
            refresh();
        }

    } while (!isNumber(input));

    return stoi(input);
}

vector<int> getPositions(Map &map){
  vector<int> positions;
  while (true){

    int row, col;

    map.printDMap();
    row = getUserInput("Please enter the chosen x position: ");
    col = getUserInput("Please enter the chosen y position: ");
    if (row >= 0 && row < map.getCols() && col >= 0 && col < map.getRows()){
      if (map.getCell(row, col) == 0){
        instruction("");
        positions.push_back(row);
        positions.push_back(col);
        return positions;
      }else{
        instruction("You have already chosen this position, please try again!(Press any key to continue)");
        getch();
      }
    }
    else{
      instruction("Coordinates are out of range, please try again!(Press any key to continue)");
      getch();
        }
    }
}



void changeValue(vector<int> Postions, Map &map, Map &map1){
  int row = Postions[0];
  int col = Postions[1];
  int value = map.getCell(row, col);
  if (value == 0){
    map1.setCell(row, col, 1);
    map1.printDMap();
    instruction("Oops! You miss the shot!(Press any key to continue)");
    getch();
  }
  else{
    for (int i = 0; i < map.getCols(); i++){
      for (int j = 0; j < map.getRows(); j++){
        if (map.getCell(i, j) == value){
          map1.setCell(i, j, value);
          map.setCell(i, j, 1);
          map1.printDMap();
        }
      }
    }
    instruction("Congratulations! you hit one ship successfully!(Press any key to continue)");
    getch();
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
    game = true;
  }
  return game;
}
