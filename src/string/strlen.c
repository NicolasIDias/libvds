#include <vds/types.h>

size_t strlen(const char *string)
{
    size_t len = 0;

    while (string[len] != '\0')
        len++;

    return len;
}