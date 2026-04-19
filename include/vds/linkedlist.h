#pragma once

#include <vds/types.h>

typedef struct node_t
{
	void *val;
	struct node_t *next;
} Node;

typedef struct list_t
{
	Node *first;
	Node *last;
	int counter;
} LinkedList;

LinkedList *create_list(void);
Node *create_node(VDS_NONNULL void *data);
int insert_node(VDS_NONNULL LinkedList *list, VDS_NONNULL void *data);