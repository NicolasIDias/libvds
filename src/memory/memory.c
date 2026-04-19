#include <vds/vds_memory.h>
#include <vds/vds_types.h>
#include <vds/vds_assert.h>

void *vds_memcpy(VDS_NONNULL void *dest, VDS_NONNULL const void *src, vds_size_t count)
{
    vds_assert(dest != NULL);
    vds_assert(src != NULL);

    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (count--)
    {
        *d++ = *s++;
    }

    return dest;
}