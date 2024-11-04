#include "Process.h"

Process::Process(const std::string &name, int burstTime, std::string processName, int instructionCount)
        : name(name), burstTime(burstTime), processName(processName), instructionCount(instructionCount) {}

std::string Process::getName() const {
    return name;
}

int Process::getBurstTime() const {
    return burstTime;
}

void Process::setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}

int Process::getCoreAssigned() const {
    return coreAssigned;
}

void Process::setCoreAssigned(int coreAssigned) {
    this->coreAssigned = coreAssigned;
}

int Process::getInstructionsExecuted() const {
    return instructionsExecuted;
}

void Process::setInstructionsExecuted(int instructionsExecuted) {
    this->instructionsExecuted = instructionsExecuted;
}

std::string Process::getProcessName() const {
    return processName;
}

int Process::getInstructionCount() const {
    return instructionCount;
}

void Process::setInstructionCount(int c) {
    this->instructionCount = instructionCount;
}


