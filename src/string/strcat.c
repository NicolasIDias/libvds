#include <vds/vds_string.h>
#include <vds/vds_types.h>

char *vds_strcat(VDS_NONNULL char *dest, VDS_NONNULL const char *src, vds_size_t n)
{
    vds_size_t dest_len = vds_strlen(dest);
    if (n == 0 || dest_len >= n - 1)
    {
        return dest;
    }
    vds_size_t i = dest_len;

    vds_size_t j = 0;

    while (src[j] != '\0' && i < (n - 1))
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}