#ifndef SCREEN_COMMAND_H
#define SCREEN_COMMAND_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Scheduler.h"  // for cpu utilixation 

class ScreenCommand {
private:
    static std::vector<std::string> screens;
    Scheduler* scheduler;

    bool screenExists(const std::string &screenName) const {
        return std::find(screens.begin(), screens.end(), screenName) != screens.end();
    }

public:
    ScreenCommand(Scheduler* schedulerInstance) : scheduler(schedulerInstance) {} 

    void processScreenCommand(const std::string &option, const std::string &screenName);
    void handleScreenCommands();
    void listScreens();
    void retrieveScreen(const std::string &screenName);
};

#endif
