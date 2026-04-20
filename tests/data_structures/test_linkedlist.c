#include <stdio.h>
#include <stdlib.h>
#include <vds/vds_linkedlist.h>
#include <vds/vds_assert.h>

int main(void)
{
    printf("[TEST] Validating VDSLinkedList implementation...\n");

    VDSLinkedList *list = vds_ll_create();
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

    VDSLinkedList *list2 = vds_ll_create();
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

    VDSLinkedList *list3 = vds_ll_create();
    int front_val1 = 100;
    vds_ll_push_front(list3, &front_val1);
    vds_assert(list3->counter == 1);
    vds_assert(*(int *)list3->first->val == 100);
    vds_assert(list3->first == list3->last);
    printf("[PASS] vds_ll_push_front: Single element insertion.\n");

    int front_val2 = 200;
    vds_ll_push_front(list3, &front_val2);
    vds_assert(list3->counter == 2);
    vds_assert(*(int *)list3->first->val == 200);
    vds_assert(*(int *)list3->last->val == 100);
    vds_assert(list3->first->next == list3->last);
    printf("[PASS] vds_ll_push_front: Multiple element insertion.\n");

    int front_val3 = 300;
    vds_ll_push_front(list3, &front_val3);
    vds_assert(list3->counter == 3);
    vds_assert(*(int *)list3->first->val == 300);
    vds_assert(*(int *)list3->first->next->val == 200);
    vds_assert(*(int *)list3->last->val == 100);
    printf("[PASS] vds_ll_push_front: Order verified (300 → 200 → 100).\n");

    vds_ll_pop_back(list3);
    vds_assert(list3->counter == 2);
    vds_assert(*(int *)list3->last->val == 200);
    vds_assert(list3->last->next == NULL);
    printf("[PASS] vds_ll_pop_back: Removed last element, counter = 2.\n");

    vds_ll_pop_back(list3);
    vds_assert(list3->counter == 1);
    vds_assert(*(int *)list3->first->val == 300);
    vds_assert(list3->first == list3->last);
    vds_assert(list3->last->next == NULL);
    printf("[PASS] vds_ll_pop_back: Single element remaining.\n");

    vds_ll_pop_back(list3);
    vds_assert(list3->counter == 0);
    vds_assert(list3->first == NULL);
    vds_assert(list3->last == NULL);
    printf("[PASS] vds_ll_pop_back: List emptied.\n");

    int pop_val1 = 11;
    int pop_val2 = 22;
    int pop_val3 = 33;
    vds_ll_push_back(list3, &pop_val1);
    vds_ll_push_back(list3, &pop_val2);
    vds_ll_push_back(list3, &pop_val3);
    vds_assert(list3->counter == 3);
    printf("[PASS] Test setup for vds_ll_pop_front: 3 elements inserted.\n");

    vds_ll_pop_front(list3);
    vds_assert(list3->counter == 2);
    vds_assert(*(int *)list3->first->val == 22);
    vds_assert(*(int *)list3->last->val == 33);
    printf("[PASS] vds_ll_pop_front: Removed first element, counter = 2.\n");

    vds_ll_pop_front(list3);
    vds_assert(list3->counter == 1);
    vds_assert(list3->first == list3->last);
    vds_assert(*(int *)list3->first->val == 33);
    printf("[PASS] vds_ll_pop_front: Single element remaining.\n");

    vds_ll_pop_front(list3);
    vds_assert(list3->counter == 0);
    vds_assert(list3->first == NULL);
    vds_assert(list3->last == NULL);
    printf("[PASS] vds_ll_pop_front: List emptied.\n");

    VDSLinkedList *list4 = vds_ll_create();
    int *destroy_vals[5];
    for (int i = 0; i < 5; i++)
    {
        destroy_vals[i] = malloc(sizeof(int));
        *destroy_vals[i] = i * 100;
        vds_ll_push_back(list4, destroy_vals[i]);
    }
    vds_assert(list4->counter == 5);
    printf("[PASS] Test setup for vds_ll_destroy: 5 elements inserted.\n");

    vds_ll_destroy(list4);
    vds_assert(list4->first == NULL);
    vds_assert(list4->last == NULL);
    vds_assert(list4->counter == 0);
    printf("[PASS] vds_ll_destroy: List structure properly cleared.\n");

    for (int i = 0; i < 5; i++)
        free(destroy_vals[i]);

    VDSLinkedList *list5 = vds_ll_create();
    int inter_val1 = 1000, inter_val2 = 2000, inter_val3 = 3000, inter_val4 = 4000;

    vds_ll_push_back(list5, &inter_val1);     
    vds_assert(list5->counter == 1);
    vds_ll_push_front(list5, &inter_val2);   
    vds_assert(list5->counter == 2);
    vds_ll_push_back(list5, &inter_val3);     
    vds_assert(list5->counter == 3);
    vds_ll_push_front(list5, &inter_val4);    
    vds_assert(list5->counter == 4);

    vds_assert(*(int *)list5->first->val == 4000);
    vds_assert(*(int *)list5->last->val == 3000);
    printf("[PASS] Intercalated pushes completed: [4000, 2000, 1000, 3000].\n");

    vds_ll_pop_front(list5);                    
    vds_assert(list5->counter == 3);
    vds_assert(*(int *)list5->first->val == 2000);
    vds_ll_pop_back(list5);                    
    vds_assert(list5->counter == 2);
    vds_assert(*(int *)list5->last->val == 1000);
    printf("[PASS] Intercalated pops completed: counter = 2.\n");

    vds_ll_pop_back(list5);                     
    vds_assert(list5->counter == 1);
    vds_assert(list5->first == list5->last);
    vds_assert(*(int *)list5->first->val == 2000);
    printf("[PASS] After intercalated operations, single element remains.\n");

    vds_ll_destroy(list5);
    vds_assert(list5->first == NULL);
    vds_assert(list5->last == NULL);
    vds_assert(list5->counter == 0);
    printf("[PASS] vds_ll_destroy: Remaining intercalated list destroyed.\n");

    VDSLinkedList *list6 = vds_ll_create();
    int seq_val1 = 111, seq_val2 = 222, seq_val3 = 333;
    vds_ll_push_back(list6, &seq_val1);
    vds_ll_push_back(list6, &seq_val2);
    vds_ll_push_back(list6, &seq_val3);
    vds_assert(list6->counter == 3);
    printf("[PASS] Test setup: 3 sequential elements [111, 222, 333].\n");

    vds_ll_pop_front(list6);
    vds_ll_pop_front(list6);
    vds_ll_pop_front(list6);
    vds_assert(list6->counter == 0);
    vds_assert(list6->first == NULL);
    vds_assert(list6->last == NULL);
    printf("[PASS] Sequential pop_front emptied list cleanly.\n");

    VDSLinkedList *list7 = vds_ll_create();
    int cycle_vals[3];
    for (int cycle = 0; cycle < 3; cycle++)
    {
        cycle_vals[cycle] = cycle * 50;
        vds_ll_push_front(list7, &cycle_vals[cycle]);
    }
    vds_assert(list7->counter == 3);
    for (int cycle = 0; cycle < 2; cycle++)
    {
        vds_ll_pop_back(list7);
    }
    vds_assert(list7->counter == 1);
    printf("[PASS] Mixed push_front/pop_back cycle: counter = 1.\n");

    vds_ll_destroy(list7);
    vds_assert(list7->first == NULL);
    vds_assert(list7->last == NULL);
    vds_assert(list7->counter == 0);

    free(list3);
    free(list4);
    free(list5);
    free(list6);
    free(list7);

    printf("[TEST] VDSLinkedList validation completed.\n\n");
    return 0;
}
