// #include "ReportCommand.h"
// #include "Scheduler.h"
// #include <iostream>
// #include <fstream>
// #include <filesystem>

// extern Scheduler scheduler;

// void ReportCommand::runReportUtil() {

//     std::filesystem::path current_dir = std::filesystem::current_path();
//     std::ofstream outputFile("csopesy-log.txt");
//     std::cout << "Running report utility...\n";

//     if (outputFile.is_open()) {

//         int coresUsed = scheduler.getCoresUsed();
//         int totalCores = scheduler.getNumCores();
//         double cpuUtilization = scheduler.getCpuUtilization();
//         const std::vector<Process>& allProcesses = scheduler.getAllProcesses();

//         outputFile << "=== Screen -ls Report ===\n";
//         outputFile << "Total Cores: " << totalCores << "\n";
//         outputFile << "Cores in Use: " << coresUsed << "\n";
//         outputFile << "CPU Utilization: " << cpuUtilization << "%\n\n";
//         outputFile << "Processes:\n";

//         for (const auto& process : allProcesses) {
//             outputFile << "Process Name: " << process.getName() << "\n";
//             outputFile << "Instruction Count: " << process.getInstructionCount() << "\n";
//             outputFile << "Instructions Executed: " << process.getInstructionsExecuted() << "\n";
//             outputFile << "Core Assigned: " << process.getCoreAssigned() << "\n";
//             outputFile << "---------------------------\n";
//         }

//         std::cout << "Report successfully written to " << current_dir / "csopesy-log.txt" << std::endl;
//     } else {
//         std::cout << "Something went wrong while opening the file!" << std::endl;
//     }
// }
