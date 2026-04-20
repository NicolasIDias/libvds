#include <stdio.h>
#include <stdlib.h>
#include <vds/vds_linkedlist.h>
#include <vds/vds_assert.h>

int main(void)
{
    printf("[TEST] Validating VDSLinkedList implementation...\n");

    VDSLinkedList *list = create_list();
    vds_assert(list != NULL);
    vds_assert(list->first == NULL);
    vds_assert(list->last == NULL);
    vds_assert(list->counter == 0);
    printf("[PASS] List created: empty with counter = 0.\n");

    int val1 = 10;
    int result1 = vds_ll_push_back(list, &val1);
    vds_assert(result1 == 0);
    vds_assert(list->first != NULL);
    vds_assert(list->last != NULL);
    vds_assert(list->counter == 1);
    vds_assert(*(int *)list->first->val == 10);
    printf("[PASS] First VDSLLNode inserted: value = 10, counter = 1.\n");

    int val2 = 20;
    int result2 = vds_ll_push_back(list, &val2);
    vds_assert(result2 == 0);
    vds_assert(list->counter == 2);
    vds_assert(list->first->next == list->last);
    vds_assert(*(int *)list->last->val == 20);
    printf("[PASS] Second VDSLLNode inserted: value = 20, counter = 2.\n");

    int val3 = 30;
    vds_ll_push_back(list, &val3);
    vds_assert(list->counter == 3);
    vds_assert(list->last->next == NULL);
    vds_assert(*(int *)list->last->val == 30);
    printf("[PASS] Third VDSLLNode inserted: value = 30, counter = 3.\n");

    vds_assert(*(int *)list->first->val == 10);
    vds_assert(*(int *)list->first->next->val == 20);
    vds_assert(*(int *)list->first->next->next->val == 30);
    printf("[PASS] Insertion order verified: 10 → 20 → 30.\n");

    int *ptr_val = NULL;
    vds_ll_push_back(list, ptr_val);
    vds_assert(list->counter == 4);
    vds_assert(list->last->val == NULL);
    printf("[PASS] VDSLLNode with NULL value inserted, counter = 4.\n");

    VDSLinkedList *list2 = create_list();
    for (int i = 0; i < 10; i++)
    {
        int *val = malloc(sizeof(int));
        *val = i * 10;
        vds_ll_push_back(list2, val);
    }
    vds_assert(list2->counter == 10);
    vds_assert(*(int *)list2->first->val == 0);
    vds_assert(*(int *)list2->last->val == 90);
    printf("[PASS] 10 VDSLLNodes inserted, counter = 10.\n");

    VDSLLNode *current = list2->first;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    vds_assert(count == 10);
    printf("[PASS] Linking verified: 10 VDSLLNodes found.\n");

    for (int i = 0; i < 10; i++)
    {
        VDSLLNode *temp = list2->first;
        list2->first = list2->first->next;
        free(temp->val);
        free(temp);
    }
    free(list2);

    for (int i = 0; i < 4; i++)
    {
        VDSLLNode *temp = list->first;
        list->first = list->first->next;
        free(temp);
    }
    free(list);

    printf("[TEST] VDSLinkedList validation completed.\n\n");
    return 0;
}
