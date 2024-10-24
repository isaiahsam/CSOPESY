#include <iostream>
#include <sstream>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#endif
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>  
#endif

#include "MainMenu.h"
#include "ScreenCommand.h"

#include "ReportCommand.h"
#include <ctime>
#include <iomanip>
#include "Config.h"
#include "Scheduler.h"

// to see if my pookie bear is initialized
bool isInitialized = false;

void MainMenu::displayMainMenu() {
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

    static Scheduler* scheduler = nullptr;

    if (!isInitialized && command != "initialize" && command != "exit") {
        std::cout << "Initialize First.\n";
        return;
    }

    if (command == "initialize") {
        Config loadedConfig("config.txt");
        loadedConfig.loadConfig();
        scheduler = new Scheduler(loadedConfig);
        isInitialized = true;
        std::cout << "Initialized using config.txt\n";
        scheduler->displayConfig();
    } else if (cmd == "screen") {
        ScreenCommand screenCommand;
        screenCommand.processScreenCommand(option, screenName);
    } else if (command == "scheduler-test") {
        if (scheduler) {
            scheduler->startSchedulerTest();
        } else {
            std::cout << "Scheduler not initialized.\n";
        }
    } else if (command == "scheduler-stop") {
        if (scheduler) {
            scheduler->stopSchedulerTest();
        } else {
            std::cout << "Scheduler not initialized.\n";
        }
    } else if (command == "report-util") {
        ReportCommand reportCommand;
        reportCommand.runReportUtil();
    } else if (command == "clear") {
        clearScreen();
        displayMainMenu();
    } else if (command == "exit") {
        std::cout << "Exiting the application.\n";
        if (scheduler) {
            delete scheduler;
        }
        exit(0);
    } else {
        std::cout << "Unknown command. Try again.\n";
    }
}
