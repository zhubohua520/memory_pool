//
// Created by zbh on 2021/8/8.
//
#pragma once

#include "../common.h"


class MemoryCell {

public:

    MemoryCell(uint start, uint size);

    ~MemoryCell();


private:
    uint start;
    uint end;
    uint size;

public:
    uint get_start();

    MemoryCell *set_start(uint start);

    uint get_end();

    MemoryCell *set_end(uint end);

    uint get_size();

    MemoryCell *set_size(uint size);


public:

    void to_string();

    void to_string(char *msg);
};


