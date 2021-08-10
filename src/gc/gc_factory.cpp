//
// Created by zbh on 2021/8/10.
//

#include "../../include/gc/gc_factory.h"
#include "../../include/gc/mark_clean.h"
#include "../../include/gc/mark_collect.h"
#include "../../include/gc/mark_copy.h"


GarbageCollect *GCFactory::get_garbage_collect() {


    if (status == STOP) {
        INFO_PRINT("GC在运行中...\n");
        return nullptr;
    }


    switch (DEFAULT_GC_TYPE) {
        case GC_MARK_CLEAN: {
            MarkClean *clean = new MarkClean();

            return (GarbageCollect *) clean;
        }
        case GC_MARK_COLLECT: {
            MarkCollect *collect = new MarkCollect();

            return (GarbageCollect *) collect;
        }
        case GC_MARK_COPY: {
            MarkCopy *copy = new MarkCopy();

            return (GarbageCollect *) copy;
        }
        case GC_G1: {
            ERROR_PRINT("没有实现G1\n");
            exit(1);
        }
    }
    return nullptr;
}