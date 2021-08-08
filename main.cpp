#include <iostream>

#include "include/common.h"
#include "include/memory/memory_pool.h"
#include "include/memory/memory_cell.h"

int main() {

//    MemoryCell* cell = new MemoryCell(0, 20);

//    delete(cell);

    MemoryPool *pool = new MemoryPool(156);
    pool->get_chunk()->malloc(8);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
