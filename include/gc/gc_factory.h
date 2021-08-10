//
// Created by zbh on 2021/8/10.
//

#include "interface/garbage_collect.h"
#include "mark_clean.h"

typedef enum {
    WORKING,
    STOP
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
    GarbageCollect *get_garbage_collect();


};



