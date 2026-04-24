#include <vds/vds_string.h>
#include <vds/vds_types.h>

vds_size_t vds_strlen(VDS_NONNULL const char *string)
{
    vds_size_t len = 0;

    while (string[len] != '\0')
        len++;

    return len;
}