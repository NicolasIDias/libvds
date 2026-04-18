#include <vds/assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vds/types.h>

void vds_assert_fail(const char *expr, const char *file, int line, const char *func)
{
    fprintf(stderr,
            "\n[ASSERT FAILED]\n"
            "Expression: %s\n"
            "Location:   %s:%d\n"
            "Function:   %s\n",
            expr, file, line, func);

    abort();
}