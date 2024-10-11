#include "Process.h"

Process::Process(int id, int numPrints, const std::string& printString)
    : id(id), numPrints(numPrints), printCount(0), printString(printString) {
    outFile.open("Process_" + std::to_string(id) + ".txt");
    outFile << "Process name: process_" << id << "\nLogs:\n";
}

void Process::executePrintCommand(int coreId) {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    //std::lock_guard<std::mutex> lock(mtx);
    outFile << "(" << std::put_time(std::localtime(&now), "%m/%d/%Y %H:%M:%S") << ") Core:" << coreId << " \"" << printString << "\"\n";
    printCount++;
}

int Process::getPrintCount() const {
    return printCount;
}

int Process::getNumPrints() const {
    return numPrints;
}

void Process::run(int coreId) {
    for (int i = 0; i < numPrints; ++i) {
        executePrintCommand(coreId);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
    outFile << "Process " << id << " finished.\n";
    outFile.close();
}

int Process::getId() const {
    return id;
}