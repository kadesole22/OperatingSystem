#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <string>
#include <queue>

// DeviceManager class is responsible for managing devices and their interrupts
class DeviceManager {
    // Queue that stores interrupt events to be handled
    std::queue<std::string> interruptQueue;

public:

    // Function prototypes
    void sendToDevice(const std::string& device, const std::string& data);
    void generateInterrupt(const std::string& device);
    void handleInterrupts();
};

#endif
