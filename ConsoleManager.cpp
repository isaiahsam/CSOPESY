#include <iostream>

#include "ConsoleManager.h"
#include "MainMenu.h"

void ConsoleManager::startConsole()
{
    MainMenu mainMenu;

    mainMenu.displayMainMenu();

    // Get the input command for main menu
    std::string command;
    while (true)
    {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);

        mainMenu.processCommand(command);
    }
}