#include "Process.h"

Process::Process(const std::string &name, int burstTime)
    : name(name), burstTime(burstTime) {}

std::string Process::getName() const {
    return name;
}

int Process::getBurstTime() const {
    return burstTime;
}

void Process::setBurstTime(int burstTime) {
    this->burstTime = burstTime;
}