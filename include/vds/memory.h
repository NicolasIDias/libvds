#pragma once
#include <vds/types.h>

typedef struct Arena
{
    void *base;
    vds_size_t size;
    vds_size_t offset;
} arena_t;

void *vds_memcpy(VDS_NONNULL void *dest, VDS_NONNULL const void *src, vds_size_t count);