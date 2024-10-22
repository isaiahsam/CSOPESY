#include "SchedulerCommand.h"
#include <iostream>

void SchedulerCommand::processSchedulerCommand(const std::string &command) {
    if (command == "scheduler-test") {
        std::cout << "Running scheduler-test...\n";
        // Logic to test the scheduler
    } else if (command == "scheduler-stop") {
        std::cout << "Stopping the scheduler...\n";
        // Logic to stop the scheduler
    } else {
        std::cout << "Unknown scheduler command.\n";
    }
}
