//
// Created by zbh on 2021/8/10.
//

#include "../../include/gc/mark_collect.h"
#include <list>

void MarkCollect::run(MemoryChunk *chunk) {

    //先排序,再合并没有使用的内存
    list<MemoryCell *> *available_list = chunk->get_available_list();

//    list<MemoryCell *>::iterator iterator = available_list->begin();

    //快排

    list<MemoryCell *>::iterator left = available_list->begin();
    list<MemoryCell *>::iterator right = available_list->end();

    list<MemoryCell *>::iterator pivot = available_list->end();


    while (left != right) {

        MemoryCell *left_cell = *left;
        MemoryCell *right_cell = *right;
        MemoryCell *pivot_cell = *pivot;

        if (left_cell->get_start() > pivot_cell->get_start()) {

            list<MemoryCell *>::iterator temp = left;
            left = pivot;

            available_list->sort(123)

        }


    }

//    while (iterator != available_list->end()) {
//
//
//        iterator++;
//    }


}
