//
// Created by zbh on 2021/8/8.
//

#include "../../include/memory/memory_chunk.h"


MemoryChunk::MemoryChunk(uint size) {

    INFO_PRINT("��ʼ�����ڴ�\n");
    align = ALIGN_SIZE;

    //��ʼ��chunk��С
    cell_num = (size - 1) / align + 1;

    size = cell_num * align;
    INFO_PRINT("ʵ���ڴ��СΪ��%d\n", size);
    //��ʵ�����ڴ�
    data = calloc(size, sizeof(byte));


    MemoryCell *cell = new MemoryCell(0, cell_num);
//    if (NULL == available_list) {
//        available_list = new list<MemoryCell *>;
//    }

    available_list->push_front(cell);


}

MemoryChunk::~MemoryChunk() {
    INFO_PRINT("������������\n");
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
        ERROR_PRINT("�޷������ڴ�,����GC\n");
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
