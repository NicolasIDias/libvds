#include <vds/linkedlist.h>
#include <vds/types.h>
#include <vds/memory.h>
#include <vds/assert.h>
#include <stdlib.h> // will be changed later with vds_alloc (current in defvelopment)

Node *create_node(VDS_NONNULL void *data, size_t data_size) {
    Node *new_node = malloc(sizeof(Node));
    vds_assert(new_node != NULL);

    new_node->val = malloc(data_size);

    vds_assert(new_node->val != NULL);

    vds_memcpy(new_node->val, data, data_size);

    new_node->next = NULL;
    return new_node;
}