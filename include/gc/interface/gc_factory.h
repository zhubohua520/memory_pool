//
// Created by zbh on 2021/8/9.
//
#pragma once

#include "../../memory/memory_chunk.h"


class GCFactory {

public:
    virtual void run(MemoryChunk *chunk) = 0;

};