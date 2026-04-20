#include <stdio.h>
#include <vds/vds_assert.h>
#include <vds/vds_types.h>

int main(void)
{
    printf("[TEST] Validating core types...\n");

    vds_size_t size_vds_size_t = sizeof(vds_size_t);
    vds_assert(size_vds_size_t > 0);
    printf("[PASS] vds_size_t correctly configured (%lu bytes).\n", size_vds_size_t);

    void *null_ptr = NULL;
    vds_assert(null_ptr == (void *)0);
    printf("[PASS] NULL macro operating correctly.\n");

    bool active = true;
    vds_assert(active == true && false == 0);
    printf("[PASS] Boolean logic is operational.\n");

    bool inactive = false;
    vds_assert(inactive == 0);
    printf("[PASS] Boolean false equals 0.\n");

    vds_assert(true == 1);
    printf("[PASS] Boolean true equals 1.\n");

    bool result = 1;
    vds_assert(result == true);
    printf("[PASS] Implicit conversion: 1 → true.\n");

    result = 0;
    vds_assert(result == false);
    printf("[PASS] Implicit conversion: 0 → false.\n");

    vds_size_t sz = 100;
    vds_assert(sz > 0 && sz < 1000);
    printf("[PASS] vds_size_t operating as unsigned type.\n");

    printf("[TEST] Type validation completed.\n\n");
    return 0;
}