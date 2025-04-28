#include "MemoryManager.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

PageTableEntry page_table[NUM_PAGES];           // Page table to map virtual pages withthe physical frames
char physical_memory[NUM_FRAMES][PAGE_SIZE];    // Physical memory with fixed number and size of the frames
char disk[NUM_PAGES][PAGE_SIZE];                // A disk simulation which is really just a 2D array
std::queue<int> fifo_queue;                     // Fifo queue

int timestamp = 0;                              // Timestamp for managing the last used page

// Page table initializer
void init_page_table() {
    for (int i = 0; i < NUM_PAGES; ++i) {
        page_table[i] = PageTableEntry();       // Default constructor which will set valid = false and frame_number = -1
    }
}


// Load a page from the disk into a specific frame
void load_page_from_disk(int page_number, int frame) {
    std::memcpy(physical_memory[frame], disk[page_number], PAGE_SIZE); // Copy page content from disk to the memory
}


// Function to replace the least recently used page. It will return the frame that was made free
int replace_page_LRU() {
    int oldest = INT_MAX;       // Tracks oldest page
    int victim = -1;            // Page thats going to be replaced


    // Find the least recently used page
    for (int i = 0; i < NUM_PAGES; ++i) {
        if (page_table[i].valid && page_table[i].last_used < oldest) {
            oldest = page_table[i].last_used;
            victim = i;
        }
    }

    // Obtain the frame of the page that we need to replace
    int frame = page_table[victim].frame_number;
    page_table[victim].valid = false;   // Mark the page as invalid becausse we need to replace it
    return frame;
}
// Function to rplace the page at the front of the FIFO queue i made
int replace_page_FIFO() {
    int victim = fifo_queue.front();    // First page in the queue becomes the victim
    fifo_queue.pop();                   // Pop it from the queue to remove it 
    int frame = page_table[victim].frame_number;
    page_table[victim].valid = false;   // Mark the page as invalid because it needs to get replaced
    return frame;
}


// Tries to find a free frame
int find_free_frame() {
    for (int i = 0; i < NUM_FRAMES; ++i) {
        bool used = false;
        for (auto& entry : page_table) {
            if (entry.valid && entry.frame_number == i) {
                used = true;            // Frame is being used
                break;
            }
        }
        if (!used) return i;            // Found a frame thats currently available
    }
    return -1;                          // No free frame is available causing a fault
}


// Handles page fualt by loading the page into mem after doing the LRU algorithm. If the LRU algorithm cannot work it will resort to the FIFO one
void handle_page_fault(int page_number, const std::string& algorithm) {
    int frame = find_free_frame();      // Attempt to find an available page frame


    if (frame == -1) {                  // If there is none, use the replacement algorithm
        if (algorithm == "LRU")
            frame = replace_page_LRU();
        else
            frame = replace_page_FIFO();
    }

    // Load the page from disk into the frame
    load_page_from_disk(page_number, frame);
    page_table[page_number].frame_number = frame;   // Update the page table with the frame number
    page_table[page_number].valid = true;           // Mark the page as valid
    page_table[page_number].last_used = timestamp;  // Update the last used for the LRU algorithm

    if (algorithm == "FIFO")
        fifo_queue.push(page_number);

    std::cout << "Page fault handled: loaded page " << page_number
        << " into frame " << frame << "\n";
}


// Access mem at the virtual address
char access_memory(int virtual_address, const std::string& algorithm) {
    int page_number = virtual_address / PAGE_SIZE;     // get the page number
    int offset = virtual_address % PAGE_SIZE;          // get the offset

    if (!page_table[page_number].valid)                // If the page is not loaded deal witht he page fault
        handle_page_fault(page_number, algorithm);

    page_table[page_number].last_used = timestamp++;    // Update the last used timestamp
    int frame = page_table[page_number].frame_number;   // Get the correct page frame
    return physical_memory[frame][offset];              // Return the value from the physical memory at the specific offset
}
