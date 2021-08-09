//
// Created by zbh on 2021/8/9.
//

#pragma once

#include "interface/gc_factory.h"


class MarkClean : public GCFactory {




public:
    void run(MemoryChunk *chunk) override;

};


