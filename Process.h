// Process.h
#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>

class Process {
public:
    Process(int id, int numPrints, const std::string& printString);
    void executePrintCommand(int coreId);
    void run(int coreId);
    int getId() const;
    int getPrintCount() const;
    int getNumPrints() const;

private:
    int id;
    int numPrints;
    int printCount;
    std::string printString;
    std::ofstream outFile;
    std::mutex mtx;
};
#endif // PROCESS_H