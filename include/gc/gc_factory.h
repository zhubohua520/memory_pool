//
// Created by zbh on 2021/8/10.
//

#include "interface/garbage_collect.h"
#include "mark_clean.h"
#include <map>

typedef enum {
    STOP,
    WORKING
} GC_Status;


class GCFactory {


private:
    GC_Status status;



public :
    static GCFactory *get_instance() {
        static GCFactory factory;

        return &factory;
    }


public:
    void run_garbage_collect(MemoryChunk *chunk, GC_Type gc_type);


};



