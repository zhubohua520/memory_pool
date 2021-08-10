//
// Created by zbh on 2021/8/9.
//

#include "../../include/gc/mark_clean.h"
#include <list>


using namespace std;

void MarkClean::run(MemoryChunk *chunk) {

    list<MemoryCell *> *used_list = chunk->get_used_list();

    INFO_PRINT("我进来了\n");


}
