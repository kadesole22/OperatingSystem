#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "fileSystem.h"    // Include the file system header
#include "memoryManager.h" // Include the memory manager header
#include "scheduler.h"     // Include the scheduler header

fileSystem fs; // Declare fileSystem object
memoryManager mm; // Declare memoryManager object
scheduler sch; // Declare scheduler object

void startShell() {
    std::string input;
    while (true) {
        std::cout << "MiniOS> ";
        std::getline(std::cin, input);

        if (input.empty()) continue;

        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;

        while (iss >> token) tokens.push_back(token);

        std::string command = tokens[0];

        if (command == "exit") {
            std::cout << "Shutting down MiniOS..." << std::endl;
            break;
        }
        else if (command == "help") {
            std::cout << "Commands: help, exit, ps, load, kill, mem, ls, mkdir, touch, cat\n";
        }
        // Handle File System commands
        else if (command == "mkdir" && tokens.size() == 2) {
            fs.createFile(tokens[1]);
        }
        else if (command == "rm") {
            fs.deleteFile();
        }
        else if (command == "cat") {
            fs.readFile();
        }
        else if (command == ">") {
            fs.writeFile();
        }
        else if (command == "ls") {
            fs.listFiles();
        }
        /*
        // Handle Memory System commands
        else if (command == "mem" && tokens.size() >= 2) {
            if (tokens[1] == "load" && tokens.size() == 3) {
                mm.loadProcess(std::stoi(tokens[2]));
            }
            else if (tokens[1] == "free" && tokens.size() == 3) {
                mm.freeProcess(std::stoi(tokens[2]));
            }
            else if (tokens[1] == "status") {
                mm.printStatus();
            }
        }
        */
        /*
        // Handle PCB commands
        else if (command == "ps") {
            sch.printProcesses();
        }
        else if (command == "load" && tokens.size() == 2) {
            sch.loadProcess(tokens[1]);
        }
        else if (command == "kill" && tokens.size() == 2) {
            sch.killProcess(std::stoi(tokens[1]));
        }
        else if (command == "run") {
            sch.runNext();
        }
        else {
            std::cout << "Unknown command: " << command << std::endl;
        }
        */
    }
}

int main() {
    fs.init();  // Initialize file system
    mm.init();  // Initialize memory manager
    sch.init(); // Initialize scheduler

    startShell(); // Start the shell

    return 0;
}
