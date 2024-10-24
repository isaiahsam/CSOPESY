#pragma once
#include <string>

class Process {
public:
    Process(const std::string &name, int burstTime);

    std::string getName() const;
    int getBurstTime() const;
    void setBurstTime(int burstTime);

private:
    std::string name;
    int burstTime;
};