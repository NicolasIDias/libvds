#pragma once
#include <vds/types.h>


typedef struct Arena {
    void *base;
    size_t size;
    size_t offset;
} arena_t;

arena_t vds_arena_init(size_t size);
void *vds_alloc(size_t size, arena_t *arena);
void vds_arena_reset(arena_t *arena);
void vds_arena_destroy(arena_t *arena);