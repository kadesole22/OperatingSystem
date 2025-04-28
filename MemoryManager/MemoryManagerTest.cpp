#include "MemoryManager.h"
#include <iostream>
#include <cstdlib>

int main() {
    // Create the page table
    init_page_table();


    // Fill the disk with testing data to simulate a real test
    for (int i = 0; i < NUM_PAGES; ++i)         // Iterate through the pages
        for (int j = 0; j < PAGE_SIZE; ++j)     // Itearte through each byte in the page
            disk[i][j] = 'A' + (i % 26);        // Assign random alphabet characters to act as "data" 

    // Setting the algorithm for page replacement to LRU
    std::string algorithm = "LRU";

    // Simulates 100 memory access
    for (int i = 0; i < 100; ++i) {
        // Randomly generaetes virtual address to access
        int virtual_address = rand() % (PAGE_SIZE * NUM_PAGES);

        // Access mem at the given virtual address using the LRU algorithm for faults
        char value = access_memory(virtual_address, algorithm);

        // Output the result of the mem access
        std::cout << "Accessed virtual address " << virtual_address
            << ", value: " << value << "\n";
    }

    return 0;
}
