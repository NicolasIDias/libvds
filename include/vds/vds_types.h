#pragma once

#ifndef bool
#define bool _Bool
#define true 1
#define false 0
#endif

#ifdef __SIZE_TYPE__
typedef __SIZE_TYPE__ vds_size_t;
#else
typedef unsigned long vds_size_t;
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#define VDS_NONNULL
#define VDS_NULLABLE