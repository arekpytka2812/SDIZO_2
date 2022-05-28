
#include "FileManager.h"

FileManager::FileManager()
{
    this->readFromFile();
}

FileManager::~FileManager()
{
    this->graphFile.close();

    delete[] this->table;

    this->edgesNumber = 0;
    this->nodesNumber = 0;
}

void FileManager::readFromFile()
{
    std::cout << "Type file name: \n";
    std::cin >> this->graphPath;

    // opeinig file
    this->graphFile.open(this->graphPath.c_str(), std::fstream::in);

    this->graphFile.clear();
    this->graphFile.seekg(0);

    if(this->graphFile.good())
    {
        this->graphFile >> this->edgesNumber >> this->nodesNumber;

        this->table =  new size_t [this->edgesNumber * 3];

        // inserting data into table
        for(int i = 0; i < this->edgesNumber * 3; i++)
        {
            this->graphFile >> this->table[i];
        }
    }
}