#ifndef PCB_H
#define PCB_H

#include <string>

// Enum class that represents the different states a process will be in
enum class ProcessState {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};


// PCB class that holds information about the processes
class PCB {
public:
    int pid;            // Process ID
    int priority;       // Priority level 
    ProcessState state; // Current state
    int programCounter; // Program counter for the process


    // PCB constructer / initizliare paramaters are the unique ID and the priority 
    PCB(int id, int prio)
        : pid(id), priority(prio), state(ProcessState::NEW), programCounter(0) {}


    // Returns the current process state
    std::string getStateString() const;
};

#endif
