#include <vds/vds_string.h>
#include <vds/vds_types.h>

int vds_strcmp(VDS_NONNULL const char *s1, VDS_NONNULL const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}