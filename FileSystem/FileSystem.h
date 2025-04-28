#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <unordered_map>
#include <vector>


// Struct to represent a file with a name and its content
struct File {
    std::string name;       // Name of the file
    std::string content;    // Content of the file
};


// Directory class that represents a collection of files and provides operations to manage them
class Directory {
public:
    std::unordered_map<std::string, File> files;

    //Function prototypes
    bool createFile(const std::string& filename);
    bool deleteFile(const std::string& filename);
    bool writeFile(const std::string& filename, const std::string& data);
    std::string readFile(const std::string& filename);
    void listFiles();
};

#endif
