#include <vds/types.h>

size_t vds_strlen(VDS_NONNULL const char *string);
int vds_strcmp(VDS_NONNULL const char *string1, VDS_NONNULL const char *string2);
char *vds_strcpy(VDS_NONNULL char *dest, VDS_NONNULL const char *src, size_t n);
char *vds_strcat(VDS_NONNULL char *dest, VDS_NONNULL const char *src, size_t n);
