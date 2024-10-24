#include "Scheduler.h"
#include <iostream>
#include <chrono>
#include <thread>

Scheduler::Scheduler(const Config &config)
    : numCpu(config.getNumCpu()),
      scheduler(config.getScheduler()),
      quantumCycles(config.getQuantumCycles()),
      batchProcessFreq(config.getBatchProcessFreq()),
      minIns(config.getMinIns()),
      maxIns(config.getMaxIns()),
      delaysPerExec(config.getDelaysPerExec()),
      running(false),
      cpuStatus(numCpu, ""),
      currentInstructions(numCpu, 0),
      totalInstructions(numCpu, 0),
      schedulerThread(),
      monitorThread() {}

Scheduler::~Scheduler() {
    if (running) {
        stopSchedulerTest();
    }
}

void Scheduler::addProcess(const Process &process) {
    std::lock_guard<std::mutex> lock(queueMutex);
    processQueue.push(process);
    condition.notify_one();
}

void Scheduler::schedule() {
    for (int i = 0; i < numCpu; ++i) {
        cpuThreads.emplace_back(&Scheduler::processTasks, this, i);
    }
}

void Scheduler::processTasks(int cpuIndex) {
    while (running) {
        Process currentProcess("", 0);
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return !processQueue.empty() || !running; });

            if (!running && processQueue.empty()) {
                return;
            }

            currentProcess = processQueue.front();
            processQueue.pop();
        }

        cpuStatus[cpuIndex] = currentProcess.getName();
        int instructions = rand() % (maxIns - minIns + 1) + minIns;
        totalInstructions[cpuIndex] = instructions;
        currentInstructions[cpuIndex] = 0;

        if (scheduler == "fcfs") {
            // FCFS scheduling logic
            for (int i = 0; i < instructions; ++i) {
                currentInstructions[cpuIndex] = i + 1;
                std::this_thread::sleep_for(std::chrono::milliseconds(globalDelay));
            }
        } else if (scheduler == "rr") {
            // RR scheduling logic
        }

        std::cout << "CPU " << cpuIndex << " processed " << currentProcess.getName() << " for " << instructions << " instructions.\n";

        cpuStatus[cpuIndex] = "";
        currentInstructions[cpuIndex] = 0;
        totalInstructions[cpuIndex] = 0;

        finishedProcesses.push_back(currentProcess.getName());
    }
}

void Scheduler::monitorStatus() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(globalDelay));
        printProcessQueue();
        printCPUStatus();
    }
}

void Scheduler::displayConfig() const {
    std::cout << "Scheduler Configuration:\n";
    std::cout << "Number of CPUs: " << numCpu << "\n";
    std::cout << "Scheduler Algorithm: " << scheduler << "\n";
    std::cout << "Quantum Cycles: " << quantumCycles << "\n";
    std::cout << "Batch Process Frequency: " << batchProcessFreq << "\n";
    std::cout << "Minimum Instructions per Process: " << minIns << "\n";
    std::cout << "Maximum Instructions per Process: " << maxIns << "\n";
    std::cout << "Delays per Execution: " << delaysPerExec << "\n";
}

void Scheduler::startSchedulerTest() {
    if (!running) {
        running = true;
        schedulerThread = std::thread(&Scheduler::generateDummyProcesses, this);
        monitorThread = std::thread(&Scheduler::monitorStatus, this);
        schedule();
        std::cout << "Scheduler test started.\n";
    } else {
        std::cout << "Scheduler test is already running.\n";
    }
}

void Scheduler::stopSchedulerTest() {
    if (running) {
        running = false;
        condition.notify_all();
        schedulerThread.join();
        monitorThread.join();
        for (auto &thread : cpuThreads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
        std::cout << "Scheduler test stopped.\n";
    } else {
        std::cout << "Scheduler test is not running.\n";
    }
}

void Scheduler::generateDummyProcesses() {
    int processCount = 1;
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(batchProcessFreq));
        std::string processName = "p" + std::to_string(processCount++);
        Process newProcess(processName, rand() % (maxIns - minIns + 1) + minIns);
        addProcess(newProcess);
        std::cout << "Generated process: " << processName << "\n";
    }
}
int Scheduler::getBatchProcessFreq() const {
    return batchProcessFreq;
}

int Scheduler::getMinIns() const {
    return minIns;
}

int Scheduler::getMaxIns() const {
    return maxIns;
}

void Scheduler::printProcessQueue() const {
    std::queue<Process> tempQueue = processQueue;
    std::cout << "Process Queue: ";
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front().getName() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;
}

void Scheduler::printCPUStatus() const {
    std::cout << "CPU Status: " << std::endl;
    for (size_t i = 0; i < cpuStatus.size(); ++i) {
        std::cout << "CPU " << i << ": " << (cpuStatus[i].empty() ? "Idle" : cpuStatus[i])
                  << " Instructions: " << currentInstructions[i] << "/" << totalInstructions[i] << std::endl;
    }
    std::cout << "Finished Processes: ";
    for (const auto &process : finishedProcesses) {
        std::cout << process << " ";
    }
    std::cout << std::endl;
}