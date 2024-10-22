// #include <string>
// #include <vector>

// class MainMenu
// {

// private:
//     std::vector<std::string> screens; // this will be used to store screen names (processes)

// public:
//     void displayMainMenu();

//     void clearScreen();

//     void processCommand(const std::string &command);

//     bool screenExists(const std::string &name);

//     void startMarquee();

//     void displayNvidiaSmi();
// };

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>

class MainMenu {
public:
    void displayMainMenu();
    void processCommand(const std::string &command);
    void clearScreen();
};

#endif
