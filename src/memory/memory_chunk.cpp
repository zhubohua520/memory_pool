//
// Created by zbh on 2021/8/8.
//

#include "../../include/memory/memory_chunk.h"



MemoryChunk::MemoryChunk(uint size) {
    PRINT("开始申请内存\n");
    align = ALIGN_SIZE;

    //初始化chunk大小
    cell_num = (size - 1) / align + 1;

    size = cell_num * align;

    //真实分配内存
    data = calloc(size, sizeof(byte));


}
