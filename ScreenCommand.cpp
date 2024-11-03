#include "ScreenCommand.h"
#include "ScreenLayout.h"
#include <iostream>

// Define the static screens vector
std::vector<std::string> ScreenCommand::screens;

void ScreenCommand::processScreenCommand(const std::string &option, const std::string &screenName) {
    if (option == "-s") {
        if (screenName.empty()) {
            std::cout << "Please provide a screen name.\n";
        } else {
            if (screenExists(screenName)) {
                std::cout << "The screen '" << screenName << "' already exists.\n";
            } else {
                screens.push_back(screenName); // Add screen to the stored list
                ScreenLayout screenLayout;
                screenLayout.displayScreenLayout(screenName);
                handleScreenCommands();
            }
        }
    } else if (option == "-r") {
        retrieveScreen(screenName);
    } else if (option == "-ls") {
        listScreens();
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

// Lists all active screens
void ScreenCommand::listScreens() {
    if (screens.empty()) {
        std::cout << "No active screens.\n";
    } else {
        std::cout << "Active screens:\n";
        for (const auto &screen : screens) {
            std::cout << "  - " << screen << "\n";
        }
    }
}

// Retrieves a specific screen, if it exists
void ScreenCommand::retrieveScreen(const std::string &screenName) {
    if (screenExists(screenName)) {
        ScreenLayout screenLayout;
        screenLayout.displayScreenLayout(screenName);
        handleScreenCommands();
    } else {
        std::cout << "Process '" << screenName << "' not found.\n";
    }
}
