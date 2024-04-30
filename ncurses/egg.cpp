#include "egg.h"

//For playing the ASCII art viedo 

void egg() {
    const string relativePath = "store/storeframe_"; //Locating the path of the size containing the ASCII art files
    WINDOW* buffer = newpad(1000, 1000);   //Create a new buffer window of size 1000 x 1000 to avoid flickering

    for (int i = 0; i <= 606; i++) {
        ifstream file(relativePath + to_string(i) + ".txt");          //606 is the total number of the frames of the ASCII art

        if (file) {
            string line;
            int line_num = 0;
            werase(buffer);
            while (getline(file, line)) {
                mvwprintw(buffer, line_num++, 0, "%s", line.c_str());
        }
        prefresh(buffer, 0, 0, 0, 0, LINES - 1, COLS - 1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/30));
        file.close();
    }
    delwin(buffer);
    return;
}
