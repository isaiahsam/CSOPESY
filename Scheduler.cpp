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
      monitorThread() {
}

Scheduler::~Scheduler() {
    if (running) {
        stopSchedulerTest();
    }
}

//for screen -ls
int Scheduler::getCoresUsed() const {
    int activeCores = 0;
    for (const auto &status: cpuStatus) {
        if (!status.empty()) activeCores++;
    }
    return activeCores;
}

int Scheduler::getNumCores() const {
    return numCpu;
}

double Scheduler::getCpuUtilization() const {
    int totalInstructions = 0, executedInstructions = 0;
    for (size_t i = 0; i < currentInstructions.size(); ++i) {
        totalInstructions += this->totalInstructions[i];
        executedInstructions += this->currentInstructions[i];
    }
    return totalInstructions > 0 ? (100.0 * executedInstructions / totalInstructions) : 0.0;
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
    if (scheduler == "fcfs") {
        while (running) {
            Process currentProcess("", 0, "", 0); {
                std::unique_lock<std::mutex> lock(queueMutex);
                condition.wait(lock, [this] { return !processQueue.empty() || !running; });

                if (!running && processQueue.empty()) {
                    return;
                }

                currentProcess = processQueue.front();
                processQueue.pop();
            }

            cpuStatus[cpuIndex] = currentProcess.getName();
            currentProcess.setCoreAssigned(cpuIndex);
            int instructions = currentProcess.getInstructionCount();
            totalInstructions[cpuIndex] = instructions;
            currentInstructions[cpuIndex] = 0;


            // FCFS scheduling logic
            for (int i = 0; i < instructions; ++i) {
                currentInstructions[cpuIndex] = i + 1;
                currentProcess.setInstructionsExecuted(i + 1);
                std::this_thread::sleep_for(std::chrono::milliseconds(globalDelay));
            }

            std::cout << "CPU " << cpuIndex << " processed " << currentProcess.getName() << " for " << instructions <<
                    " instructions.\n";

            cpuStatus[cpuIndex] = "";
            currentInstructions[cpuIndex] = 0;
            totalInstructions[cpuIndex] = 0;

            finishedProcesses.push_back(currentProcess.getName());
        }
    } else if (scheduler == "rr") {
        while (running) {
            Process currentProcess("", 0, "", 0); {
                std::unique_lock<std::mutex> lock(queueMutex);
                condition.wait(lock, [this] { return !processQueue.empty() || !running; });

                if (!running && processQueue.empty()) {
                    return;
                }

                currentProcess = processQueue.front();
                processQueue.pop();
            }

            cpuStatus[cpuIndex] = currentProcess.getName();
            currentProcess.setCoreAssigned(cpuIndex);
            int instructionsLeft = currentProcess.getInstructionCount() - currentProcess.getInstructionsExecuted();
            totalInstructions[cpuIndex] = currentProcess.getInstructionCount();
            currentInstructions[cpuIndex] = currentProcess.getInstructionsExecuted();

            // RR scheduling logic
            int cycles = std::min(quantumCycles, instructionsLeft);
            for (int i = 0; i < cycles; ++i) {
                currentInstructions[cpuIndex]++;
                currentProcess.setInstructionsExecuted(currentProcess.getInstructionsExecuted() + 1);
                std::this_thread::sleep_for(std::chrono::milliseconds(globalDelay));
            }



            if (currentProcess.getInstructionsExecuted() < currentProcess.getInstructionCount()) {
                std::lock_guard<std::mutex> lock(queueMutex);
                processQueue.push(currentProcess);
            } else {
                std::cout << "CPU " << cpuIndex << " processed " << currentProcess.getName() << " for " << currentProcess.getInstructionsExecuted() << " instructions.\n";
                finishedProcesses.push_back(currentProcess.getName());
            }

            cpuStatus[cpuIndex] = "";
            currentInstructions[cpuIndex] = 0;
            totalInstructions[cpuIndex] = 0;
        }
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
        allProcesses.clear();
        // monitorThread = std::thread(&Scheduler::monitorStatus, this);
        schedule();
        schedulerThread = std::thread(&Scheduler::generateDummyProcesses, this);
        std::cout << "Scheduler test started.\n";
    } else {
        std::cout << "Scheduler test is already running.\n";
    }
}

void Scheduler::stopSchedulerTest() {
    if (running) {
        std::cout << "stopping " << std::endl;
        running = false;
        if (schedulerThread.joinable()) {
            std::cout << "Stopping process generator thread\n";
            schedulerThread.join();
        }
        if (monitorThread.joinable()) {
            monitorThread.join();
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
        int instructionCount = rand() % (maxIns - minIns + 1) + minIns;
        Process newProcess(processName, instructionCount, processName, instructionCount);
        addProcess(newProcess);
        allProcesses.push_back(newProcess);
        std::cout << "Generated process: " << processName << " with instructions:" << newProcess.getInstructionCount()
                << "\n";
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
    int activeCores = getCoresUsed();
    int totalCores = getNumCores();
    double cpuUtil = static_cast<double>(activeCores) / totalCores * 100.0;
    std::cout << "CPU Status: " << std::endl;
    std::cout << "CPU Utilization: " << cpuUtil << "%" << std::endl;
    for (size_t i = 0; i < cpuStatus.size(); ++i) {
        std::cout << "CPU " << i << ": " << (cpuStatus[i].empty() ? "Idle" : cpuStatus[i])
                << " Instructions: " << currentInstructions[i] << "/" << totalInstructions[i] << std::endl;
    }
    std::cout << "Finished Processes: ";
    for (const auto &process: finishedProcesses) {
        std::cout << process << " ";
    }
    std::cout << std::endl;
}

std::vector<Process> Scheduler::getAllProcesses() const {
    return allProcesses;
}
