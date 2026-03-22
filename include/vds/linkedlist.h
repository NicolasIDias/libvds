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