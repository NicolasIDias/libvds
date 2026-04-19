#pragma once
#include <vds/vds_types.h>

typedef struct vds_vector_t
{
    void *data;
    vds_size_t length;
    vds_size_t capacity;
    vds_size_t element_size;
} VDSVector;