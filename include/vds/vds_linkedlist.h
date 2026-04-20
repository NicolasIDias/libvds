#pragma once

#include <vds/vds_types.h>

typedef struct VDSLLNode_t
{
    void *val;
    struct VDSLLNode_t *next;
} VDSLLNode;

typedef struct list_t
{
    VDSLLNode *first;
    VDSLLNode *last;
    int counter;
} VDSLinkedList;

VDSLinkedList *vds_ll_create(void);
VDSLLNode *vds_ll_create_node(VDS_NONNULL void *data);
int vds_ll_push_back(VDS_NONNULL VDSLinkedList *list, VDS_NONNULL void *data);
int vds_ll_push_front(VDS_NONNULL VDSLinkedList *list, VDS_NONNULL void *data);
int vds_ll_pop_back(VDS_NONNULL VDSLinkedList *list);
int vds_ll_pop_front(VDS_NONNULL VDSLinkedList *list);
void vds_ll_destroy(VDS_NONNULL VDSLinkedList *list);