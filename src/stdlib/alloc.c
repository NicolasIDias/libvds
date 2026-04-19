// Currently im studying how to implement this

#include <vds/memory.h>
#include <vds/types.h>

arena_t vds_arena_init(size_t size)
{
    arena_t arena;
    
    arena.base = NULL;
    arena.size = 0;
    arena.offset = 0;

    if (size == 0) {
        return arena;
    }

    void *ptr = NULL;
}