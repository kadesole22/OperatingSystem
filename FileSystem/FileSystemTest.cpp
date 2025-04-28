#include "FileSystem.h"
#include "DeviceManager.h"
#include <iostream>

int main() {
    // Create a root directory for testing
    Directory root;

    // Create a file named "hello.txt" in the directory
    root.createFile("hello.txt");

    // Adds the string "Hello, World!" to the hello.txt file
    root.writeFile("hello.txt", "Hello, World!");

    // Couts the content of the hello.txt file
    std::cout << "Read from hello.txt: " << root.readFile("hello.txt") << "\n";

    //Lists all files in the root directory
    root.listFiles();


    // Creates a device manager object to test the device manager system for I/O
    DeviceManager devMgr;

    // Tests with 2 simulated devices
    devMgr.sendToDevice("Printer", "Print this text.");
    devMgr.sendToDevice("Disk", "Save this block.");

    // Handles interrupts in the queue such as the printer or disk interupts
    devMgr.handleInterrupts();

    return 0;
}
