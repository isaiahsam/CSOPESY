#include "ScreenCommand.h"
#include "ScreenLayout.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

std::map<std::string, ScreenCommand::InstructionData> ScreenCommand::screenData;

bool ScreenCommand::screenExists(const std::string &screenName) const {
    return screenData.find(screenName) != screenData.end();
}

void ScreenCommand::generateInstructionLines(const std::string &screenName, int minIns, int maxIns) {
    InstructionData data;

    data.currentInstructionLines = minIns;
    data.linesOfCode = maxIns;
    screenData[screenName] = data; // Store the data for this screen
}

void ScreenCommand::processScreenCommand(const std::string &option, const std::string &screenName) {
    if (option == "-s") {
        if (screenName.empty()) {
            std::cout << "Please provide a screen name.\n";
        } else {
            if (screenExists(screenName)) {
                std::cout << "The screen '" << screenName << "' already exists.\n";
            } else {
                ScreenLayout screenLayout;
                screenLayout.displayScreenLayout(screenName);
                screens.push_back(screenName);

                if (scheduler) {
                    generateInstructionLines(screenName, scheduler->getMinIns(), scheduler->getMaxIns());
                } else {
                    std::cout << "Scheduler not initialized.\n";
                }

                activeScreen = screenName;
                handleScreenCommands();
            }
        }
    } else if (option == "process-smi") {
        processSMI();
    } else if (option == "-r") {
        retrieveScreen(screenName);
    } else if (option == "-ls") {
        listScreens();
    } else {
        std::cout << "Unknown screen command option.\n";
    }
}

void ScreenCommand::processSMI() const {
    if (activeScreen.empty()) {
        std::cout << "No active screen. Please create or retrieve a screen first.\n";
        return;
    }

    const auto& data = screenData.at(activeScreen);
    std::cout << "Current Instruction Lines: " << data.currentInstructionLines << "\n";
    std::cout << "Lines of Code: " << data.linesOfCode << "\n";
}

void ScreenCommand::retrieveScreen(const std::string &screenName) {
    if (screenExists(screenName)) {
        ScreenLayout screenLayout;
        screenLayout.displayScreenLayout(screenName);
        activeScreen = screenName;
        handleScreenCommands();
    } else {
        std::cout << "Process '" << screenName << "' not found.\n";
    }
}

void ScreenCommand::listScreens() {
    if (screenData.empty()) {
        std::cout << "No active screens.\n";
    } else {
        std::cout << "Active screens:\n";
        for (const auto &screen : screenData) {
            std::cout << "  - " << screen.first << "\n";
        }
    }

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

void ScreenCommand::handleScreenCommands() {
    std::string command;
    while (true) {
        std::cout << "root :\\> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "process-smi") {
            processSMI();
        } else if (command.find("screen -r") == 0) {
            std::istringstream ss(command);
            std::string option, screenName;
            ss >> option >> option >> screenName; // Extract 'screen -r <screenName>'
            if (!screenName.empty()) {
                retrieveScreen(screenName);
            } else {
                std::cout << "Please provide a screen name to retrieve.\n";
            }
        } else if (command == "screen -ls") {
            listScreens();
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }
}
