#include <stdio.h>
#include <vds/vds_assert.h>
#include <vds/vds_types.h>

int main(void)
{
    printf("[TEST] Validating assert module...\n");

    vds_assert(1 == 1);
    printf("[PASS] Assert with true expression (1 == 1).\n");

    int x = 10;
    vds_assert(x > 5);
    printf("[PASS] Assert with boolean operation (x > 5, x=%d).\n", x);

    vds_assert(x == 10);
    printf("[PASS] Assert with equality (x == 10).\n");

    int *ptr = &x;
    vds_assert(ptr != NULL);
    printf("[PASS] Assert with valid pointer (ptr != NULL).\n");

    int y = 20;
    vds_assert((x + y) == 30);
    printf("[PASS] Assert with multiple conditions (x + y == 30, x=%d, y=%d).\n", x, y);

    vds_assert((x > 0) && (y > 0));
    printf("[PASS] Assert with complex expression ((x > 0) && (y > 0)).\n");

    bool flag = true;
    vds_assert(flag);
    printf("[PASS] Assert with boolean (flag == true).\n");

    vds_assert(!(false));
    printf("[PASS] Assert with negation (!(false)).\n");

    printf("[TEST] Assert module validation completed.\n");
    printf("[WARNING] Failing tests cause abort() - not included in this test suite.\n\n");
    return 0;
}
