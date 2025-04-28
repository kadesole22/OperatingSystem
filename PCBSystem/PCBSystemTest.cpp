#include "scheduler.cpp"

// Testing on the pcb system
int main() {
    Scheduler scheduler;

    // Create 3 processes all with different priorities 
    scheduler.createProcess(1);
    scheduler.createProcess(2);
    scheduler.createProcess(3);

    // Run the FCFS algorithm for scheduling
    scheduler.fcfsSchedule();

    return 0;
}
