#ifndef SCREEN_COMMAND_H
#define SCREEN_COMMAND_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Scheduler.h"

class ScreenCommand {
private:
    struct InstructionData {
        int currentInstructionLines;
        int linesOfCode;
    };

    static std::map<std::string, InstructionData> screenData;
    std::vector<std::string> screens; // Add this line to store the list of screen names
    Scheduler* scheduler;
    std::string activeScreen; // To keep track of the current active screen

    bool screenExists(const std::string &screenName) const;
    void generateInstructionLines(const std::string &screenName, int minIns, int maxIns);

public:
    ScreenCommand(Scheduler* schedulerInstance) : scheduler(schedulerInstance), activeScreen("") {}

    void processScreenCommand(const std::string &option, const std::string &screenName);
    void handleScreenCommands();
    void listScreens();
    void retrieveScreen(const std::string &screenName);
    void processSMI() const;
};

#endif
