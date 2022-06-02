#include "Heap.h"

Heap::Heap()
{
    this->size = 0;
}

Heap::~Heap()
{
    delete[] this->table;
    this->table = nullptr;
    this->size = 0;
}

void Heap::heapify(int i)
{
    int min {i}, left {2*i + 1}, right {2*i + 2};

    if(left < this->size && table[left]->cost < table[min]->cost)
        min = left;

    if(right < this->size && table[right]->cost < table[min]->cost)
        min = right;

    if(min != i){
        std::swap(table[i], table[min]);

        heapify(min);
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

    this->buildHeap();
}

Edge* Heap::pop()
{
    if(this->size == 0)
        return nullptr;

    auto returnEdge = this->table[0];

    if(this->size == 1)
    {
        this->size--;
        delete[] table;
        return returnEdge;
    }

    std::swap(this->table[0], this->table[this->size - 1]);

    this->size--;

    delete this->table[this->size];

    this->buildHeap();

    return returnEdge;
}

void Heap::printHeap()
{
    if(this->size == 0)
        return;

    for(int i = 0; i < this->size; i++)
    {
        std::cout << "[" << i << "] -> " << this->table[i]->cost << "\n";
    }
}

void Heap::buildHeap()
{
    int startIndex {(this->size / 2) - 1};

    for(int i = startIndex; i >= 0; i--)
        heapify(i);
}