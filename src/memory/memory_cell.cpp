//
// Created by zbh on 2021/8/8.
//

#include "../../include/memory/memory_cell.h"

MemoryCell::MemoryCell(uint start, uint size) : start(start), size(size) {

    this->end = this->start + this->size;

    to_string("创建cell");
}


MemoryCell::~MemoryCell() {
    to_string();

    to_string("调用析构函数");

}

void MemoryCell::to_string() {
    INFO_PRINT("cell属性为：start=%d,end=%d,size=%d\n", start, end, size);
}

void MemoryCell::to_string(char *msg) {

    INFO_PRINT("[%s]\tcell属性为：start=%d,end=%d,size=%d\n", msg, start, end, size);
}

uint MemoryCell::get_start() {
    return start;
}

MemoryCell *MemoryCell::set_start(uint start) {
    this->start = start;
    return this;
}

uint MemoryCell::get_end() {
    return end;
}

MemoryCell *MemoryCell::set_end(uint end) {
    this->end = end;
    return this;
}

uint MemoryCell::get_size() {
    return size;
}

MemoryCell *MemoryCell::set_size(uint size) {
    this->size = size;
    return this;
}
