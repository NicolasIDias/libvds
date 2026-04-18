#pragma once

#define bool _Bool
#define true 1
#define false 0

typedef typeof(sizeof(0)) size_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#define VDS_NONNULL
#define VDS_NULLABLE