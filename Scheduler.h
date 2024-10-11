// Scheduler.h
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <condition_variable>
#include <queue>
#include <thread>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Process.h"

class Scheduler {
public:
    Scheduler(int numCores);
    void addProcess(std::shared_ptr<Process> process);
    void start();
    void worker(int coreId);
    void displayStatus();

private:
    int numCores;
    std::queue<std::shared_ptr<Process>> processQueue;
    std::vector<std::thread> workers;
    std::unordered_map<int, std::shared_ptr<Process>> runningProcesses;
    std::unordered_map<int, std::pair<std::time_t, int>> finishedProcesses;
    std::mutex queueMutex;
    std::mutex statusMutex;
    std::condition_variable cv;
    bool stop;
};
#endif // SCHEDULER_H