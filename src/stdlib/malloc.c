#include <vds/memory.h>
#include <vds/types.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

#elif defined(__linux__) || defined(__APPLE__)
#include <sys/mman.h>

#else
#error "Sistema Operacional nao suportado"
#endif

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