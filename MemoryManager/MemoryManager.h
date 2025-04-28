#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <string>
// Constant expressions to define the virtual memory config / limitations
constexpr int PAGE_SIZE = 256;      // Size of each page in btes
constexpr int NUM_PAGES = 64;       // Total number of pages in my virtual mem space
constexpr int NUM_FRAMES = 16;      // Total number of frames in my physical memory 

// Simuled disk which is acting as a 2D array
extern char disk[NUM_PAGES][PAGE_SIZE]; // Store the content of each page


// Structure to represent a table entry
struct PageTableEntry {
    int frame_number = -1;      //The frame where the page is stores
    bool valid = false;         // Flag to indicate if the page is loaded in memory
    int last_used = 0;          // Tracks the last access time for LRU
};

// Function Prototypes
void init_page_table();
char access_memory(int virtual_address, const std::string& algorithm);
void load_page_from_disk(int page_number, int frame);
void handle_page_fault(int page_number, const std::string& algorithm);

#endif // MEMORY_MANAGER_H