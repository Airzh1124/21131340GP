#include <ncurses.h>
#include <string>

int main() {
    initscr(); // 初始化 ncurses
    printw("Please enter a number: ");
    refresh(); // 打印提示信息

    char input[100]; // 假设最大输入长度为 100 个字符
    getstr(input); // 从用户读取一个字符串

    int userInput = std::stoi(input); // 将字符串转换为整数

    printw("You entered: %d", userInput);
    refresh();

    getch(); // 等待用户输入
    endwin(); // 关闭 ncurses

    return 0;
}