#include "pcb.h"


// Function to get the current process state
std::string PCB::getStateString() const {
    switch (state) {
    case ProcessState::NEW: return "NEW";
    case ProcessState::READY: return "READY";
    case ProcessState::RUNNING: return "RUNNING";
    case ProcessState::WAITING: return "WAITING";
    case ProcessState::TERMINATED: return "TERMINATED";
    default: return "UNKNOWN"; // If the state is invalid re return this to catch the errors
    }
}
