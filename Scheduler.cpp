#include "Scheduler.h"
#include <iostream>

Scheduler::Scheduler(int numCores) : numCores(numCores), stop(false) {
}

void Scheduler::addProcess(std::shared_ptr<Process> process) {
    std::lock_guard<std::mutex> lock(queueMutex);
    processQueue.push(process);
    cv.notify_one();
}

void Scheduler::start() {
    for (int i = 0; i < numCores; ++i) {
        workers.emplace_back(&Scheduler::worker, this, i);
    }
}

void Scheduler::worker(int coreId) {
    while (true) {
        std::shared_ptr<Process> process;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            cv.wait(lock, [this] { return !processQueue.empty() || stop; });
            if (stop && processQueue.empty()) return;
            process = processQueue.front();
            processQueue.pop();
        }
        {
            std::lock_guard<std::mutex> lock(statusMutex);
            runningProcesses[coreId] = process;
        }
        process->run(coreId);
        {
            std::lock_guard<std::mutex> lock(statusMutex);
            runningProcesses.erase(coreId);
            finishedProcesses[process->getId()] = {std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()), process->getPrintCount()};
        }
    }
}

void Scheduler::displayStatus() {
    std::lock_guard<std::mutex> lock(statusMutex);
    std::cout << "Running processes:\n";
    if (runningProcesses.empty()) {
        std::cout << "No running processes.\n";
    } else {
        for (const auto &entry: runningProcesses) {
            auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::cout << "Process " << entry.second->getId() << "    " << std::string(std::ctime(&now)).substr(0, 24) << "    Core " << entry.first << "    " << entry.second->getPrintCount() << "/"<< entry.second->getNumPrints() << "\n";
        }
    }
    std::cout << "Finished processes:\n";
    if (finishedProcesses.empty()) {
        std::cout << "No finished processes.\n";
    } else {
        for (const auto &entry: finishedProcesses) {
            std::cout << "Process " << entry.first << "    " << std::string(std::ctime(&entry.second.first)).substr(0, 24) << "    " << "Finished\n";
        }
    }
}