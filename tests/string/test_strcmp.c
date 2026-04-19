#include <stdio.h>
#include <vds/vds_string.h>
#include <vds/vds_assert.h>

int main(void)
{
    printf("[TEST] Validating strcmp function...\n");

    int cmp1 = vds_strcmp("Teste1", "Teste1");
    vds_assert(cmp1 == 0);
    printf("[PASS] Identical strings: 'Teste1' vs 'Teste1' = %d.\n", cmp1);

    int cmp2 = vds_strcmp("Apple", "Banana");
    vds_assert(cmp2 < 0);
    printf("[PASS] String1 less than String2: 'Apple' vs 'Banana' = %d.\n", cmp2);

    int cmp3 = vds_strcmp("Banana", "Apple");
    vds_assert(cmp3 > 0);
    printf("[PASS] String1 greater than String2: 'Banana' vs 'Apple' = %d.\n", cmp3);

    int cmp4 = vds_strcmp("estados unidos", "Estados Unidos");
    vds_assert(cmp4 > 0);
    printf("[PASS] Case-sensitive comparison: 'estados unidos' vs 'Estados Unidos' = %d.\n", cmp4);

    int cmp5 = vds_strcmp("Tes", "Teste");
    vds_assert(cmp5 < 0);
    printf("[PASS] String1 shorter: 'Tes' vs 'Teste' = %d.\n", cmp5);

    int cmp6 = vds_strcmp("Teste", "Tes");
    vds_assert(cmp6 > 0);
    printf("[PASS] String1 longer: 'Teste' vs 'Tes' = %d.\n", cmp6);

    int cmp7 = vds_strcmp("", "");
    vds_assert(cmp7 == 0);
    printf("[PASS] Both empty: '' vs '' = %d.\n", cmp7);

    int cmp8 = vds_strcmp("", "A");
    vds_assert(cmp8 < 0);
    printf("[PASS] String1 empty: '' vs 'A' = %d.\n", cmp8);

    int cmp9 = vds_strcmp("A", "");
    vds_assert(cmp9 > 0);
    printf("[PASS] String2 empty: 'A' vs '' = %d.\n", cmp9);

    int cmp10 = vds_strcmp("abcdefghijklmnop", "abcdefghijklmnop");
    vds_assert(cmp10 == 0);
    printf("[PASS] Identical long strings = %d.\n", cmp10);

    int cmp11 = vds_strcmp("abcXefgh", "abcYefgh");
    vds_assert(cmp11 < 0);
    printf("[PASS] Difference in middle: 'abcXefgh' vs 'abcYefgh' = %d.\n", cmp11);

    printf("[TEST] strcmp validation completed.\n\n");
    return 0;
}
