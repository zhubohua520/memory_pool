//
// Created by zbh on 2021/8/10.
//

#include "../../include/gc/gc_factory.h"
#include "../../include/gc/mark_clean.h"
#include "../../include/gc/mark_collect.h"
#include "../../include/gc/mark_copy.h"
#include "../../include/memory/memory_chunk.h"


void GCFactory::run_garbage_collect(MemoryChunk *chunk, GC_Type gc_type) {


    if (status == WORKING) {
        INFO_PRINT("GC在运行中...\n");
        return;
    }
    GarbageCollect *garbage_collect;

    status = WORKING;

    switch (gc_type) {
        case GC_MARK_CLEAN: {
            MarkClean *clean = new MarkClean();

            garbage_collect = (GarbageCollect *) clean;
            break;
        }
        case GC_MARK_COLLECT: {
            MarkCollect *collect = new MarkCollect();

            garbage_collect = (GarbageCollect *) collect;
            break;
        }
        case GC_MARK_COPY: {
            MarkCopy *copy = new MarkCopy();

            garbage_collect = (GarbageCollect *) copy;
            break;
        }
        case GC_G1: {
            ERROR_PRINT("没有实现G1\n");
            exit(1);
        }
    }

    garbage_collect->run(chunk);

    status = STOP;
}