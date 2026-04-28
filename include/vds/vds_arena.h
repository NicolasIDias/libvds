#pragma once
#include <vds/vds_types.h>

#define MB(x) ((vds_size_t)(x) << 20)

typedef struct vds_arena_block_t
{
    struct vds_arena_block_t *next;
    struct vds_arena_block_t *prev;
    vds_size_t size;
    vds_size_t used;
    vds_size_t data[];
} VDSArenaBlock;

typedef struct vds_arena_t
{
    VDSArenaBlock *first;
    VDSArenaBlock *current;
    vds_size_t chunk_size;
} VDSArena;

VDSArena *vds_arena_init(void);
