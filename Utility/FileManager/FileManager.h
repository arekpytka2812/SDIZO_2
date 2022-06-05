#ifndef SDIZO_2_FILEMANAGER_H
#define SDIZO_2_FILEMANAGER_H

#include <cstdlib>
#include <fstream>
#include <iostream>

class FileManager {

    size_t* table;
    size_t nodesNumber;
    size_t edgesNumber;

    std::fstream graphFile;
    std::string graphPath;

    std::fstream resultsFile;
    std::string resultsPath;

public:

    FileManager();

    ~FileManager();

    void readFromFile();

    void writeToFile(size_t nodesNumber, size_t density, double time);

    size_t *getTable()
    {
        return this->table;
    }

    size_t getNodesNumber()
    {
        return this->nodesNumber;
    }

    size_t getEdgesNumber()
    {
        return this->edgesNumber;
    }
};


#endif
