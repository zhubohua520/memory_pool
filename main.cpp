#include <iostream>

#include "include/common.h"
#include "include/memory/memory_pool.h"
#include "include/memory/memory_cell.h"

int main() {

//    MemoryCell* cell = new MemoryCell(0, 20);

//    delete(cell);

    MemoryPool *pool = new MemoryPool(8);
    pvoid p = pool->get_chunk()->malloc(4);

    int *p_i = (int *) p;
    *p_i = 9527;

    printf("%X\n", p);

    p = pool->get_chunk()->malloc(4);
    p_i = (int *) p;
    *p_i = 2;

    printf("%X\n", p);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
