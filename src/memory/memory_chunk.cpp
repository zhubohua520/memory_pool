//
// Created by zbh on 2021/8/8.
//

#include "../../include/memory/memory_chunk.h"


MemoryChunk::MemoryChunk(uint size) {
    INFO_PRINT("开始申请内存\n");
    align = ALIGN_SIZE;

    //初始化chunk大小
    cell_num = (size - 1) / align + 1;

    size = cell_num * align;
    INFO_PRINT("实际内存大小为：%d\n", size);
    //真实分配内存
    data = calloc(size, sizeof(byte));


    MemoryCell *cell = new MemoryCell(0, cell_num);
    available_list->push_front(cell);


}

MemoryChunk::~MemoryChunk() {
    INFO_PRINT("调用析构函数\n");
}

pvoid MemoryChunk::malloc(uint size) {

    uint need_num = (size - 1) / align + 1;

    list<MemoryCell *>::iterator iterator;

    bool flag = true;

    for (iterator = available_list->begin(); iterator != available_list->end(); iterator++) {

        MemoryCell *cell = *iterator;

        if (cell->get_size() > need_num) {
            flag = false;

            break;
        }

    }

    if (flag) {
        ERROR_PRINT("无法分配内存,触发GC\n");
        exit(1);
    }

    return nullptr;
}
