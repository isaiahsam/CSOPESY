#pragma once
#include "Config.h"
#include "Process.h"
#include <queue>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

class Scheduler {
public:
    Scheduler(const Config &config);
    ~Scheduler();

    void addProcess(const Process &process);
    void schedule();
    void displayConfig() const;

    void startSchedulerTest();
    void stopSchedulerTest();

    int getBatchProcessFreq() const;
    int getMinIns() const;
    int getMaxIns() const;

private:
    int numCpu;
    std::string scheduler;
    int quantumCycles;
    int batchProcessFreq;
    int minIns;
    int maxIns;
    int delaysPerExec;
    int globalDelay = (delaysPerExec + 1) * 100;

    std::queue<Process> processQueue;
    std::vector<std::thread> cpuThreads;
    std::vector<std::string> cpuStatus;
    std::vector<int> currentInstructions;
    std::vector<int> totalInstructions;
    std::vector<std::string> finishedProcesses; // Add this line
    std::atomic<bool> running;
    std::mutex queueMutex;
    std::condition_variable condition;

    std::thread schedulerThread;
    std::thread monitorThread;

    void generateDummyProcesses();
    void processTasks(int cpuIndex);
    void monitorStatus();

    void scheduleFCFS();
    void scheduleRR();

    void printProcessQueue() const;
    void printCPUStatus() const;
};