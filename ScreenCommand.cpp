#include "ScreenCommand.h"
#include "ScreenLayout.h"
#include <iostream>

void ScreenCommand::processScreenCommand(const std::string &option, const std::string &screenName) {
    if (option == "-s") {
        if (screenName.empty()) {
            std::cout << "Please provide a screen name.\n";
        } else {
            if (screenExists(screenName)) {
                std::cout << "The screen '" << screenName << "' already exists.\n";
            } else {
                screens.push_back(screenName); 
                ScreenLayout screenLayout;
                screenLayout.displayScreenLayout(screenName);
                handleScreenCommands();
            }
        }
    } else if (option == "-r") {
        if (screenName.empty()) {
            std::cout << "Please provide a screen name.\n";
        } else if (!screenExists(screenName)) {
            std::cout << "The screen does not exist yet. Try again!\n";
        } else {
            ScreenLayout screenLayout;
            screenLayout.displayScreenLayout(screenName);
            handleScreenCommands();
        }
    } else {
        std::cout << "Unknown screen command option.\n";
    }
}

void ScreenCommand::handleScreenCommands() {
    bool isScreenLayoutActive = true;
    std::string screenCommand;

    while (isScreenLayoutActive) {
        std::cout << "root:\\> ";
        std::getline(std::cin, screenCommand);

        if (screenCommand == "exit") {
            isScreenLayoutActive = false;
        } else {
            std::cout << "\nUnknown command input. Try again.\n\n";
        }
    }
}
