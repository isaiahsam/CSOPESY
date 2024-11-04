#include "ReportCommand.h"
#include <iostream>
#include <fstream>
#include <filesystem> 

void ReportCommand::runReportUtil() {
    // Logic for report generation
    std::filesystem::path current_dir = std::filesystem::current_path();
    std::ofstream outputFile("csopesy-log.txt");
    std::cout << "Running report utility...\n";

    if(outputFile.is_open()) {
        outputFile << "Hello reports!";
        std::cout << "Report successfully written to " << current_dir / "csopesy-log.txt" << std::endl;
    } else {
        std::cout << "Something went wrong!";
    }
}
