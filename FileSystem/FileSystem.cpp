#include "FileSystem.h"
#include <iostream>


// Creates a new file with the specified filename. If the file already exists, it returns false
bool Directory::createFile(const std::string& filename) {
    // Check if the file already exists in the directory
    if (files.find(filename) != files.end()) return false;
    // Create a new file with an empty content
    files[filename] = File{ filename, "" };
    return true;
}


// Deletes a file with the specified filename. Returns true if the file was deleted, false if not found
bool Directory::deleteFile(const std::string& filename) {
    // Remove the file from the directory
    return files.erase(filename) > 0;
}


// Writes data to the specified file. If the file does not exist, it returns false
bool Directory::writeFile(const std::string& filename, const std::string& data) {
    // Check if the file exists
    if (files.find(filename) == files.end()) return false;
    // Write the data to the file's content
    files[filename].content = data;
    return true;
}


// Reads the content of a specified file. If the file doesn't exist, it returns an empty string
std::string Directory::readFile(const std::string& filename) {
    // Check if the file exists
    if (files.find(filename) == files.end()) return "";
    // Return the content of the file
    return files[filename].content;
}


// Lists all the filenames in the directory
void Directory::listFiles() {
    // Iterate over the files in the directory and print their names
    for (const auto& [name, file] : files) {
        std::cout << name << "\n";
    }
}
