#include <vds/vds_vector.h>
#include <vds/vds_types.h>
#include <vds/vds_memory.h>
#include <vds/vds_assert.h>
#include <stdlib.h> // temorary until i develop my arena allocator

VDSVector *vds_create_vec(vds_size_t capacity, vds_size_t data_size)
{
    VDSVector *vector = malloc(sizeof(VDSVector));
    assert(vector != NULL);
    vector->capacity = capacity;
    vector->element_size = data_size;
    vector->length = 0;
    vector->data = malloc(data_size * capacity);

    return vector;
}

int vds_vec_push(VDS_NONNULL VDSVector *vector, VDS_NONNULL void *data)
{
    if (vector->length >= vector->capacity)
    {
        vds_vec_resize(vector);
    }
    void *destination = (char *)vector->data + (vector->length * vector->element_size);
    vds_memcpy(destination, data, vector->element_size);
    vector->length++;
    return 0;
}

// int vds_vec_push_index(VDS_NONNULL VDSVector *vector, VDS_NONNULL void *data, vds_size_t index)
// {
//     if(vector->length >= vector->capacity)
//     {
//         vds_vec_resize(vector);
//     }

// }

void vds_vec_resize(VDS_NONNULL VDSVector *vector)
{
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity);
}

void vds_free_vec(VDS_NONNULL VDSVector *vector)
{
    assert(vector != NULL);
    free(vector->data);
    vector->capacity = 0;
    vector->length = 0;
    vector->element_size = 0;
    free(vector);
}