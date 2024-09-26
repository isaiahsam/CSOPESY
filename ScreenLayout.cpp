#include <iostream>
#include <ctime>
#include <iomanip>

#include "ScreenLayout.h"

std::string getCurrentTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y, %I:%M:%S %p", localTime);

    return std::string(buffer);
}

void ScreenLayout::displayScreenLayout(const std::string &screenName)
{
    std::string timestamp = getCurrentTime();
    std::cout << "\n===========================\n";
    std::cout << "The screen is activated!\n";
    std::cout << "Process: " << screenName << "\n";
    std::cout << "Total lines: #\n";
    std::cout << "Created on: " << timestamp << "\n";
    std::cout << "===========================\n\n";
}