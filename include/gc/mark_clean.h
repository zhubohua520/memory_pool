//
// Created by zbh on 2021/8/9.
//

#pragma once

#include "interface/garbage_collect.h"


class MarkClean : public GarbageCollect {



public:
    void run(MemoryChunk *chunk) override;

};


