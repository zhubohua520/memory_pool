//
// Created by zbh on 2021/8/10.
//

#pragma once

#include "interface/garbage_collect.h"

class MarkCopy : public GarbageCollect {

    void run(MemoryChunk *chunk) override;
};


