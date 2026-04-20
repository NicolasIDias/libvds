#include <vds/vds_linkedlist.h>
#include <vds/vds_types.h>
#include <vds/vds_memory.h>
#include <vds/vds_assert.h>
#include <stdlib.h>

VDSLinkedList *create_list(void)
{
    VDSLinkedList *list = malloc(sizeof(VDSLinkedList));
    vds_assert(list != NULL);

    list->first = NULL;
    list->last = NULL;
    list->counter = 0;

    return list;
}

VDSLLNode *vds_ll_create_(VDS_NONNULL void *data)
{
    VDSLLNode *node = malloc(sizeof(VDSLLNode));
    vds_assert(node != NULL);

    node->val = data;
    node->next = NULL;
    return node;
}

int vds_ll_push_back(VDS_NONNULL VDSLinkedList *list, VDS_NONNULL void *data)
{
    VDSLLNode *node = vds_ll_create_(data);
    vds_assert(node != NULL);

    if (list->first == NULL)
    {
        list->first = node;
    }
    else
    {
        list->last->next = node;
    }

    list->last = node;
    list->counter++;

    return 0;
}

int vds_ll_push_front(VDS_NONNULL VDSLinkedList *list, VDS_NONNULL void *data)
{
    VDSLLNode *node = vds_ll_create_(data);
    vds_assert(node != NULL);

    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        node->next = list->first;
        list->first = node;
    }

    list->counter++;

    return 0;
}

int vds_ll_pop_back(VDS_NONNULL VDSLinkedList *list)
{
    vds_assert(list->first != NULL);

    if (list->first->next == NULL)
    {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        list->counter--;
        return 0;
    }

    VDSLLNode *curr = list->first;
    while (curr->next->next != NULL)
        curr = curr->next;

    free(curr->next);
    curr->next = NULL;
    list->last = curr;

    list->counter--;
    return 0;
}

int vds_ll_pop_front(VDS_NONNULL VDSLinkedList *list)
{
    vds_assert(list->first != NULL);

    VDSLLNode *node_to_remove = list->first;
    list->first = list->first->next;

    if (list->first == NULL)
        list->last = NULL;

    free(node_to_remove);
    list->counter--;

    return 0;
}

void vds_ll_destroy(VDS_NONNULL VDSLinkedList *list)
{
    vds_assert(list != NULL);

    VDSLLNode *curr = list->first;

    while (curr != NULL)
    {
        VDSLLNode *next = curr->next;
        free(curr);
        curr = next;
    }

    list->first = NULL;
    list->last = NULL;
    list->counter = 0;
}