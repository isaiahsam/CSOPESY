#include "ScreenCommand.h"
#include "ScreenLayout.h"
#include <iostream>
#include <sstream>

std::vector<std::string> ScreenCommand::screens;

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

        std::istringstream iss(screenCommand);
        std::string command;
        std::string option;
        iss >> command; 
        if (iss) iss >> option; 
        
        std::string argument;
        if (option == "-r") {
            if (iss) iss >> argument; 
        }

        if (command == "screen") {
            if (option == "-ls") {
                listScreens();
            } else if (option == "-r") {
                if (argument.empty()) {
                    std::cout << "Please provide a screen name after '-r'.\n";
                } else {
                    retrieveScreen(argument);
                }
            } else {
                std::cout << "\nUnknown screen command option.\n";
            }
        } else if (command == "exit") {
            isScreenLayoutActive = false;
        } else {
            std::cout << "\nUnknown command input. Try again.\n\n";
        }
    }
}

void ScreenCommand::listScreens() {
    if (screens.empty()) {
        std::cout << "No active screens.\n";
    } else {
        std::cout << "Active screens:\n";
        for (const auto &screen : screens) {
            std::cout << "  - " << screen << "\n";
        }
    }

    // Retrieve CPU utilization and core data from Scheduler
    if (scheduler) {
        int coresUsed = scheduler->getCoresUsed();
        int totalCores = scheduler->getNumCores();
        int coresAvailable = totalCores - coresUsed;
        double cpuUtilization = scheduler->getCpuUtilization();

        std::cout << "CPU Utilization: " << cpuUtilization << "%\n";
        std::cout << "Cores used: " << coresUsed << "\n";
        std::cout << "Cores available: " << coresAvailable << "\n";
    } else {
        std::cout << "Scheduler not initialized.\n";
    }
}


void ScreenCommand::retrieveScreen(const std::string &screenName) {
    if (screenExists(screenName)) {
        ScreenLayout screenLayout;
        screenLayout.displayScreenLayout(screenName);
        handleScreenCommands();
    } else {
        std::cout << "Process '" << screenName << "' not found.\n";
    }
}
