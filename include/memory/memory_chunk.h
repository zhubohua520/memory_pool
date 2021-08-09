//
// Created by zbh on 2021/8/8.
//

#pragma once

#include "memory_cell.h"
#include <list>

using namespace std;

class MemoryChunk {

public:
    MemoryChunk(uint size);

    pvoid malloc(uint size);

    ~MemoryChunk();

private:

    uint align;

    uint size;

    uint cell_num;

    //真实内存的指针
    pvoid data;

    list<MemoryCell *> *available_list = new list<MemoryCell *>();

    list<MemoryCell *> *used_list = new list<MemoryCell *>();

public:
    uint get_cell_num();

    MemoryChunk *set_cell_num(uint num);

    list<MemoryCell *> *get_available_list();

    list<MemoryCell *> *get_used_list();

    pvoid get_data();

    pvoid get_cell_pointer(MemoryCell *cell);


public:
    void print_available_list();

    void print_used_list();

};



