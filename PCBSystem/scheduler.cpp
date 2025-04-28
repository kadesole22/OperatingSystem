#include <iostream>
#include <vector>
#include <queue>
#include "pcb.h"

// This class handles process creation, scheduling, and deletion
class Scheduler {
private:
    int pidCounter = 0;             // Counter to assign unique ids
    std::queue<PCB*> readyQueue;    // Queue for processes that are ready
    std::vector<PCB*> allProcesses; // Dynamic array to store all processes currently created

public:
    // Creates a new process then adds to ready queue and to the all processes array
    PCB* createProcess(int priority) {
        PCB* process = new PCB(pidCounter++, priority);
        process->state = ProcessState::READY;
        allProcesses.push_back(process);
        readyQueue.push(process);
        std::cout << "Created Process PID: " << process->pid << ", Priority: " << priority << "\n";
        return process;
    }

    // Terminates the process if its found
    void terminateProcess(int pid) {
        for (PCB* p : allProcesses) {
            if (p->pid == pid && p->state != ProcessState::TERMINATED) {
                p->state = ProcessState::TERMINATED;
                std::cout << "Terminated Process PID: " << pid << "\n";
                return;
            }
        }
        std::cout << "Process not found or already terminated.\n";
    }

    // Schedules processes using the FCFS algorithm we learned about
    void fcfsSchedule() {
        while (!readyQueue.empty()) {
            PCB* current = readyQueue.front();
            readyQueue.pop();
            if (current->state != ProcessState::READY) continue;

            current->state = ProcessState::RUNNING;
            std::cout << "Running Process PID: " << current->pid << "\n";
            // Simulate some execution
            current->programCounter += 1;

            // Terminate after "execution"
            current->state = ProcessState::TERMINATED;
            std::cout << "Process PID: " << current->pid << " finished execution.\n";
        }
    }
    // Destructor to cleam up any PCB objects because im using new which will store the objects on the heap instead of the stack
    ~Scheduler() {
        for (PCB* p : allProcesses) delete p;
    }
};
