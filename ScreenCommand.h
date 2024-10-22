#ifndef SCREEN_COMMAND_H
#define SCREEN_COMMAND_H

#include <string>
#include <vector>
#include <algorithm> // Include this for std::find

class ScreenCommand {
private:
    std::vector<std::string> screens;

    bool screenExists(const std::string &screenName) {
        return std::find(screens.begin(), screens.end(), screenName) != screens.end();
    }

public:
    void processScreenCommand(const std::string &option, const std::string &screenName);
    void handleScreenCommands();
};

#endif
