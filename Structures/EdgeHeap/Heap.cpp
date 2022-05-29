#include "Heap.h"

Heap::Heap()
{

}

Heap::~Heap()
{
    delete[] this->table;
    this->table = nullptr;
    this->size = 0;
}

void Heap::heapify()
{
    int i = this->size - 1;
    int parent = (i - 1)/2;

    while(this->table[parent]->cost > this->table[i]->cost)
    {
        std::swap(this->table[parent], this->table[i]);

        i = parent;
        parent = (i - 1) / 2;
    }
}


Edge* Heap::operator[](int position)
{
    if(position < 0 || position >= this->size)
        throw new std::out_of_range("You are out of range");

    else
        return *(table + position);
}


void Heap::push(Edge* edge)
{
    if(this-> size == 0)
    {
        this->size++;
        this->table = new Edge* [this->size];
        this->table[0] = edge;

        return;
    }

    this->size++;

    auto tempTable = new Edge * [this->size];

    // rewriting old data to temporary table
    for(int i = 0; i < this->size - 1; i++)
    {
        tempTable[i] = this->table[i];
    }

    // adding element to the end of table
    tempTable[this->size - 1] = edge;

    // deleting old table
    for(int i = 0; i < this->size - 1; i++)
    {
        delete[] this->table[i];
    }
    delete[] this->table;

    this->table = tempTable;

    this->heapify();

}

void Heap::pop()
{

}
