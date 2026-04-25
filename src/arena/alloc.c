// Currently im studying how to implement this

#include <stdio.h> //temporary
#include <vds/vds_arena.h>
#include <vds/vds_assert.h>
#include <vds/vds_memory.h>
#include <vds/vds_types.h>

VDSArena *vds_arena_init()
{
    VDSArena *arena = malloc(sizeof(VDSArena));
    assert(arena != NULL);
    VDSArenaBlock *block = malloc(sizeof(VDSArenaBlock));
    assert(block != NULL);

    block->next = NULL;
    block->prev = NULL;
    
    arena->first = block;
    arena->current = block;

    return arena;
}
