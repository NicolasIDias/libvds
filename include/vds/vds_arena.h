#pragma once
#include <vds/vds_types.h>

typedef struct Arena
{
    void *base;
    vds_size_t size;
    vds_size_t offset;
} arena_t;