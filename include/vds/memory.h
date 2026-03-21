#pragma once
#include <vds/types.h>


typedef struct Arena {
    void *base;
    size_t size;
    size_t offset;
} arena_t;