#pragma once
#include <vds/vds_types.h>

typedef struct vds_vector_t
{
    void *data;
    vds_size_t length;
    vds_size_t capacity;
    vds_size_t element_size;
} VDSVector;

VDSVector *vds_create_vec(vds_size_t capacity, vds_size_t data_size);
int vds_vec_push(VDS_NONNULL VDSVector *vector, VDS_NONNULL void *data);
//int vds_vec_push_index(VDS_NONNULL VDSVector *vector, VDS_NONNULL void *data, vds_size_t index);
void vds_vec_resize(VDS_NONNULL VDSVector *vector);
void vds_free_vec(VDS_NONNULL VDSVector *vector);
