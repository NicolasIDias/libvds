#include <vds/types.h>

char *vds_strcpy(VDS_NONNULL char *dest, VDS_NONNULL const char *src, size_t n)
{
    if (n == 0) return dest;
    size_t i = 0;
    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    dest[n-1] = '\0';
    return dest;
}