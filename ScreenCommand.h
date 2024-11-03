#ifndef SCREEN_COMMAND_H
#define SCREEN_COMMAND_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class ScreenCommand {
private:
    static std::vector<std::string> screens; // Stores all screen names globally

    // Check if the screen already exists
    bool screenExists(const std::string &screenName) const {
        return std::find(screens.begin(), screens.end(), screenName) != screens.end();
    }

public:
    void processScreenCommand(const std::string &option, const std::string &screenName);
    void handleScreenCommands();
    void listScreens(); // For screen -ls command
    void retrieveScreen(const std::string &screenName); // For screen -r command
};

#endif
