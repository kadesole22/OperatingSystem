#include "DeviceManager.h"
#include <iostream>


// Sends data to the specified device and triggers an interrupt for the device
void DeviceManager::sendToDevice(const std::string& device, const std::string& data) {

    // Print the device and the data being sent
    std::cout << "[Device: " << device << "] Sending data: " << data << "\n";

    // Trigger an interrupt for the device after sending data
    generateInterrupt(device);
}


// Generates an interrupt for the specified device
void DeviceManager::generateInterrupt(const std::string& device) {

    // Add the device to the interrupt queue
    interruptQueue.push(device);
}


// Processes and handles all interrupts in the queue
void DeviceManager::handleInterrupts() {

    // Process each interrupt in the queue
    while (!interruptQueue.empty()) {
        // Get the next device from the interrupt queue
        std::string device = interruptQueue.front();

        // Remove the device from the queue as it's being handled
        interruptQueue.pop();

        // Print a message indicating the interrupt has been handled
        std::cout << "[Interrupt Handler] Device " << device << " completed operation.\n";
    }
}
