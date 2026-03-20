#include <vds/types.h>
#include <vds/string.h>

char *vds_strcat(char *dest, const char *src, size_t n)
{
    size_t dest_len = vds_strlen(dest);
    if (n == 0 || dest_len >= n - 1)
    {
        return dest;
    }
    size_t i = dest_len;

    size_t j = 0;

    while (src[j] != '\0' && i < (n - 1))
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}