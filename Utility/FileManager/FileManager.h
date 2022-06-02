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

public:

    FileManager();

    ~FileManager();

    void readFromFile();

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
