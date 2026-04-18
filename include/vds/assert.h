#pragma once

#include <stdio.h> 
#include <stdlib.h>
#include <vds/types.h>

// pre preprocessor flag -DNDBUG
#ifdef NDEBUG
    #define vds_assert(expression) ((void)0)
#else
    #define vds_assert(expression) \
        do { \
            if (!(expression)) { \
                vds_assert_fail(#expression, __FILE__, __LINE__, __func__); \
            } \
        } while (0)

    void vds_assert_fail(const char *expr, const char *file, int line, const char *func);
#endif