#pragma once
#include <string>

class Process {
public:
    Process(const std::string &name, int burstTime, std::string processName, int instructionCount);

    std::string getName() const;
    std::string getProcessName() const;
    int getInstructionCount() const;
    int getInstructionsExecuted() const;
    int getCoreAssigned() const;
    void setCoreAssigned(int coreAssigned) ;
    void setInstructionsExecuted(int instructionsExecuted) ;
    void setInstructionCount(int instructionCount) ;


    int getBurstTime() const;
    void setBurstTime(int burstTime);


private:
    std::string processName;
    int instructionCount;
    int instructionsExecuted;
    std::string name;
    int burstTime;
    int coreAssigned;

};