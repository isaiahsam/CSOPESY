#include <iostream>
#include "Scheduler.h"

int main() {
    const int numCores = 4;
    const int numProcesses = 10;
    const int numPrints = 100;
    const std::string printString = "This is a print command";

    Scheduler scheduler(numCores);



    //make 10 processes


    // auto process0 = std::make_shared<Process>(0, 32, "Print command for process 0");
    // auto process1 = std::make_shared<Process>(1, 80, "Print command for process 1");
    // auto process2 = std::make_shared<Process>(2, 96, "Print command for process 2");
    // auto process3 = std::make_shared<Process>(3, 100, "Print command for process 3");
    // auto process4 = std::make_shared<Process>(4, 100, "Print command for process 4");
    // auto process5 = std::make_shared<Process>(5, 60, "Print command for process 5");
    // auto process6 = std::make_shared<Process>(6, 100, "Print command for process 6");
    // auto process7 = std::make_shared<Process>(7, 100, "Print command for process 7");
    // auto process8 = std::make_shared<Process>(8, 100, "Print command for process 8");
    // auto process9 = std::make_shared<Process>(9, 100, "Print command for process 9");
    //
    // // Add each process to the scheduler
    // scheduler.addProcess(process0);
    // scheduler.addProcess(process1);
    // scheduler.addProcess(process2);
    // scheduler.addProcess(process3);
    // scheduler.addProcess(process4);
    // scheduler.addProcess(process5);
    // scheduler.addProcess(process6);
    // scheduler.addProcess(process7);
    // scheduler.addProcess(process8);
    // scheduler.addProcess(process9);
    for (int i = 0; i < numProcesses; ++i) {
        auto process = std::make_shared<Process>(i, numPrints, printString);
        scheduler.addProcess(process);
    }


    scheduler.start();
    std::thread statusThread([&scheduler]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            scheduler.displayStatus();
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Type 'exit' to close the emulator or 'screen -ls' to show running processes.\n";
    std::string command;
    while (std::getline(std::cin, command)) {
        if (command == "exit") {
            break;
        } else if (command == "screen -ls") {
            scheduler.displayStatus();
        }
    }

    return 0;
}
