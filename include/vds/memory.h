#pragma once
#include <vds/types.h>

typedef struct Arena
{
    void *base;
    size_t size;
    size_t offset;
} arena_t;

void *vds_memcpy(VDS_NONNULL void *dest, VDS_NONNULL const void *src, size_t count);