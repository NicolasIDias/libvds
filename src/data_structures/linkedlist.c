#include <vds/linkedlist.h>
#include <vds/types.h>
#include <vds/memory.h>
#include <vds/assert.h>
#include <stdlib.h> // will be changed later with vds_alloc (current in defvelopment)

LinkedList *create_list()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    vds_assert(list != NULL);

    list->first = NULL;
    list->last = NULL;
    list->counter = 0;

    return list;
}

Node *create_node(VDS_NONNULL void *data)
{
    Node *new_node = malloc(sizeof(Node));
    vds_assert(new_node != NULL);

    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

int insert_node(VDS_NONNULL LinkedList *list, VDS_NONNULL void *data)
{
    Node *node = create_node(data);
    vds_assert(node != NULL);

    if (list->first == NULL) {
        list->first = node;
    } else {
        list->last->next = node;
    }

    list->last = node;
    list->counter++;

    return 0;
}