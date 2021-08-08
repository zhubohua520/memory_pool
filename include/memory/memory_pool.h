//
// Created by zbh on 2021/8/8.
//

#pragma once

#include "memory_chunk.h"

class MemoryPool {


public:
    MemoryPool(uint size);

    ~MemoryPool();


private:
    MemoryChunk *chunk;

public:
    MemoryChunk *get_chunk();

};



