//
// Created by zbh on 2021/8/9.
//

#include "../../include/gc/mark_clean.h"
#include "../../include/gc/mark_collect.h"
#include <list>


using namespace std;

void MarkClean::run(MemoryChunk *chunk) {

    list<MemoryCell *> *used_list = chunk->get_used_list();
    list<MemoryCell *> *available_list = chunk->get_available_list();

    list<MemoryCell *>::iterator iterator;
    for (iterator = used_list->begin(); iterator != used_list->end(); iterator++) {
        MemoryCell *cell = *iterator;

        iterator = used_list->erase(iterator);

        available_list->push_front(cell);

    }

    GarbageCollect *garbage_collect = new MarkCollect();

    INFO_PRINT("清除已完成\n");
    garbage_collect->run(chunk);

}
