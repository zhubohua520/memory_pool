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
//    if (NULL == available_list) {
//        available_list = new list<MemoryCell *>;
//    }

    available_list->push_front(cell);


}

MemoryChunk::~MemoryChunk() {
    INFO_PRINT("调用析构函数\n");
}

pvoid MemoryChunk::malloc(uint size) {

    uint need_num = (size - 1) / align + 1;

    list<MemoryCell *>::iterator iterator;

    bool flag = true;

    pvoid p;

    for (iterator = available_list->begin(); iterator != available_list->end(); iterator++) {

        MemoryCell *cell = *iterator;

        if (cell->get_size() > need_num) {
            flag = false;

            MemoryCell *split_cell = cell->split_front(need_num);

            used_list->push_front(split_cell);

            p = get_cell_pointer(split_cell);

            break;
        }

    }

    if (flag) {
        ERROR_PRINT("无法分配内存,触发GC\n");
        exit(1);
    }

    return p;
}

pvoid MemoryChunk::get_data() {
    return data;
}

pvoid MemoryChunk::get_cell_pointer(MemoryCell *cell) {

    return (pvoid) ((ulong) data + cell->get_start() * align);
}
