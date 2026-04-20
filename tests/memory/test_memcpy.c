#include <stdio.h>
#include <vds/vds_assert.h>
#include <vds/vds_memory.h>
#include <vds/vds_string.h>

int main(void)
{
    printf("[TEST] Validating memcpy function...\n");

    unsigned char src1[5] = {1, 2, 3, 4, 5};
    unsigned char dest1[5] = {0};
    vds_memcpy(dest1, src1, 5);
    vds_assert(dest1[0] == 1 && dest1[1] == 2 && dest1[2] == 3 && dest1[3] == 4 && dest1[4] == 5);
    printf("[PASS] Simple byte copy: [1,2,3,4,5].\n");

    unsigned char src2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    unsigned char dest2[5] = {0};
    vds_memcpy(dest2, src2, 3);
    vds_assert(dest2[0] == 10 && dest2[1] == 20 && dest2[2] == 30);
    printf("[PASS] Partial copy: [10,20,30].\n");

    unsigned char src3[5] = {1, 2, 3, 4, 5};
    unsigned char dest3[5] = {9, 9, 9, 9, 9};
    vds_memcpy(dest3, src3, 0);
    vds_assert(dest3[0] == 9 && dest3[1] == 9);
    printf("[PASS] Zero byte copy (no changes).\n");

    char src4[] = "Hello";
    char dest4[6] = {0};
    vds_memcpy(dest4, src4, 6);
    vds_assert(vds_strcmp(dest4, "Hello") == 0);
    printf("[PASS] String copy: '%s'.\n", dest4);

    int src5[] = {100, 200, 300};
    int dest5[3] = {0};
    vds_memcpy(dest5, src5, sizeof(int) * 3);
    vds_assert(dest5[0] == 100 && dest5[1] == 200 && dest5[2] == 300);
    printf("[PASS] Integer copy: [100,200,300].\n");

    struct Point
    {
        int x;
        int y;
    } src6 = {10, 20};
    struct Point dest6 = {0, 0};
    vds_memcpy(&dest6, &src6, sizeof(struct Point));
    vds_assert(dest6.x == 10 && dest6.y == 20);
    printf("[PASS] Struct copy: x=%d, y=%d.\n", dest6.x, dest6.y);

    unsigned char src7[1] = {42};
    unsigned char dest7[1] = {0};
    vds_memcpy(dest7, src7, 1);
    vds_assert(dest7[0] == 42);
    printf("[PASS] Single byte copy: %u.\n", dest7[0]);

    printf("[TEST] memcpy validation completed.\n\n");
    return 0;
}
