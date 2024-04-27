#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <string>
#include <thread>
#include <sstream>
using namespace std;

void egg() {
    const  string relativePath = "store/storeframe_";

    for (int i = 0; i <= 606; i++) {
        ifstream file(relativePath + to_string(i) + ".txt");

        if (file) {
            string line;
           while (getline(file, line)) {
            printw("%s", line.c_str());
            printw("\n");
        }
        }
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/30));
        clear();
        file.close();
    }
    
return;
}