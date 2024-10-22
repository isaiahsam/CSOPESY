#include <iostream>
#include <sstream>
#include <conio.h> 
#ifdef _WIN32
    #include <windows.h> 
#else
    #include <unistd.h>  
#endif

#include "MainMenu.h"
#include "ScreenCommand.h"
#include "MarqueeCommand.h"
#include "NvidiaCommand.h"
#include "SchedulerCommand.h"
#include "ReportCommand.h"
#include <ctime>
#include <iomanip>

void MainMenu::displayMainMenu() {
    // Display the banner and menu options
        std::cout << R"(  
                               _____  _____  ____  _____  ______  _______     __
                              / ____|/ ____|/ __ \|  __ \|  ____|/ ____\ \   / /
                             | |    | (___ | |  | | |__) | |__  | (___  \ \_/ / 
                             | |     \___ \| |  | |  ___/|  __|  \___ \  \   /  
                             | |____ ____) | |__| | |    | |____ ____) |  | |   
                              \_____|_____/ \____/|_|    |______|_____/   |_|   
    )";
    std::cout << "                                                   \n";
    std::cout << "____________________________________________________________________________________________________________\n\n";
    std::cout << "                                          Command Line Emulator\n";
    std::cout << "\n____________________________________________________________________________________________________________\n\n";

    std::cout << "\033[32mHello, Welcome to CSOPESY command line interface!\n\n"
              << "\033[0m";

    std::cout << "\n\nList of Available Commands:\n\n";
    std::cout << "  'initialize'     - Initialize something\n";
    std::cout << "  'screen'         - Manage screen operations\n";
    std::cout << "  'scheduler-test' - Test the scheduler\n";
    std::cout << "  'scheduler-stop' - Stop the scheduler\n";
    std::cout << "  'report-util'    - Run report utility\n";
    std::cout << "  'nvidia-smi'     - Display Nvidia SMI\n";
    std::cout << "  'marquee'        - Start the marquee application\n";
    std::cout << "  'clear'          - Clear the screen\n";
    std::cout << "  'exit'           - Exit the application\n";
}

void MainMenu::clearScreen() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");
#endif
}

void MainMenu::processCommand(const std::string &command) {
    std::stringstream ss(command);
    std::string cmd, option, screenName;
    ss >> cmd >> option >> screenName;

    if (command == "initialize") {
        std::cout << "initialize command recognized. Doing something.\n";
    } else if (cmd == "screen") {
        ScreenCommand screenCommand;
        screenCommand.processScreenCommand(option, screenName);
    } else if (command == "nvidia-smi") {
        NvidiaCommand nvidiaCommand;
        nvidiaCommand.displayNvidiaSmi();
    } else if (command == "marquee") {
        MarqueeCommand marqueeCommand;
        marqueeCommand.startMarquee();
    } else if (command == "scheduler-test" || command == "scheduler-stop") {
        SchedulerCommand schedulerCommand;
        schedulerCommand.processSchedulerCommand(cmd);
    } else if (command == "report-util") {
        ReportCommand reportCommand;
        reportCommand.runReportUtil();
    } else if (command == "clear") {
        clearScreen();
        displayMainMenu();
    } else if (command == "exit") {
        std::cout << "Exiting the application.\n";
        exit(0);
    } else {
        std::cout << "Unknown command. Try again.\n";
    }
}
