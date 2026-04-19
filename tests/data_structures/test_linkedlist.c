#include <stdio.h>
#include <stdlib.h>
#include <vds/vds_linkedlist.h>
#include <vds/vds_assert.h>

int main(void)
{
    printf("[TEST] Validating LinkedList implementation...\n");

    LinkedList *list = create_list();
    vds_assert(list != NULL);
    vds_assert(list->first == NULL);
    vds_assert(list->last == NULL);
    vds_assert(list->counter == 0);
    printf("[PASS] List created: empty with counter = 0.\n");

    int val1 = 10;
    int result1 = insert_node(list, &val1);
    vds_assert(result1 == 0);
    vds_assert(list->first != NULL);
    vds_assert(list->last != NULL);
    vds_assert(list->counter == 1);
    vds_assert(*(int *)list->first->val == 10);
    printf("[PASS] First node inserted: value = 10, counter = 1.\n");

    int val2 = 20;
    int result2 = insert_node(list, &val2);
    vds_assert(result2 == 0);
    vds_assert(list->counter == 2);
    vds_assert(list->first->next == list->last);
    vds_assert(*(int *)list->last->val == 20);
    printf("[PASS] Second node inserted: value = 20, counter = 2.\n");

    int val3 = 30;
    insert_node(list, &val3);
    vds_assert(list->counter == 3);
    vds_assert(list->last->next == NULL);
    vds_assert(*(int *)list->last->val == 30);
    printf("[PASS] Third node inserted: value = 30, counter = 3.\n");

    vds_assert(*(int *)list->first->val == 10);
    vds_assert(*(int *)list->first->next->val == 20);
    vds_assert(*(int *)list->first->next->next->val == 30);
    printf("[PASS] Insertion order verified: 10 → 20 → 30.\n");

    int *ptr_val = NULL;
    insert_node(list, ptr_val);
    vds_assert(list->counter == 4);
    vds_assert(list->last->val == NULL);
    printf("[PASS] Node with NULL value inserted, counter = 4.\n");

    LinkedList *list2 = create_list();
    for (int i = 0; i < 10; i++) {
        int *val = malloc(sizeof(int));
        *val = i * 10;
        insert_node(list2, val);
    }
    vds_assert(list2->counter == 10);
    vds_assert(*(int *)list2->first->val == 0);
    vds_assert(*(int *)list2->last->val == 90);
    printf("[PASS] 10 nodes inserted, counter = 10.\n");

    Node *current = list2->first;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    vds_assert(count == 10);
    printf("[PASS] Linking verified: 10 nodes found.\n");

    for (int i = 0; i < 10; i++) {
        Node *temp = list2->first;
        list2->first = list2->first->next;
        free(temp->val);
        free(temp);
    }
    free(list2);

    for (int i = 0; i < 4; i++) {
        Node *temp = list->first;
        list->first = list->first->next;
        free(temp);
    }
    free(list);

    printf("[TEST] LinkedList validation completed.\n\n");
    return 0;
}
