#include <stdio.h>
#include <vds/vds_string.h>
#include <vds/vds_assert.h>

int main(void)
{
    printf("[TEST] Validating strlen module...\n");

    vds_size_t len1 = vds_strlen("teste");
    vds_assert(len1 == 5);
    printf("[PASS] Simple word: 'teste' = %lu.\n", len1);

    vds_size_t len2 = vds_strlen("Teste numero dois");
    vds_assert(len2 == 17);
    printf("[PASS] Phrase with spaces: 'Teste numero dois' = %lu.\n", len2);

    vds_size_t len3 = vds_strlen("");
    vds_assert(len3 == 0);
    printf("[PASS] Empty string: '' = %lu.\n", len3);

    vds_size_t len4 = vds_strlen("teste numero 3");
    vds_assert(len4 == 14);
    printf("[PASS] Alphanumeric: 'teste numero 3' = %lu.\n", len4);

    vds_size_t len5 = vds_strlen("test@#$%");
    vds_assert(len5 == 8);
    printf("[PASS] String with special characters: 'test@#$%%' = %lu.\n", len5);

    vds_size_t len6 = vds_strlen("A");
    vds_assert(len6 == 1);
    printf("[PASS] Single character string: 'A' = %lu.\n", len6);

    vds_size_t len7 = vds_strlen("Lorem ipsum dolor sit amet consectetur adipiscing elit");
    vds_assert(len7 == 54);
    printf("[PASS] Long string = %lu.\n", len7);

    printf("[TEST] strlen module validation completed.\n\n");
    return 0;
}
