#include <stdio.h>
#include <vds/vds_assert.h>
#include <vds/vds_string.h>

int main(void)
{
    printf("[TEST] Validating string concatenation (strcat) function...\n");

    char buffer[100];

    buffer[0] = '\0';
    vds_strcpy(buffer, "Hello", 100);
    vds_strcat(buffer, " World", 100);
    vds_assert(vds_strcmp(buffer, "Hello World") == 0);
    printf("[PASS] Simple concatenation: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Hello World", 100);
    vds_strcat(buffer, " extra", 15);
    vds_assert(vds_strcmp(buffer, "Hello World ex") == 0);
    printf("[PASS] Overflow safety: '%s'.\n", buffer);

    char cheio[5];
    vds_strcpy(cheio, "Full", 5);
    vds_strcat(cheio, "More", 5);
    vds_assert(vds_strcmp(cheio, "Full") == 0);
    printf("[PASS] Buffer already full: '%s'.\n", cheio);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Test", 100);
    vds_strcat(buffer, "", 100);
    vds_assert(vds_strcmp(buffer, "Test") == 0);
    printf("[PASS] Concatenate empty string: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcat(buffer, "Hello", 100);
    vds_assert(vds_strcmp(buffer, "Hello") == 0);
    printf("[PASS] Concatenate to empty string: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "A", 100);
    vds_strcat(buffer, "B", 100);
    vds_strcat(buffer, "C", 100);
    vds_assert(vds_strcmp(buffer, "ABC") == 0);
    printf("[PASS] Multiple concatenations: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Original", 100);
    vds_strcat(buffer, " Extra", 0);
    vds_assert(vds_strcmp(buffer, "Original") == 0);
    printf("[PASS] n=0 does nothing: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Test", 100);
    vds_strcat(buffer, "@#$!", 100);
    vds_assert(vds_strcmp(buffer, "Test@#$!") == 0);
    printf("[PASS] Concatenation with special characters: '%s'.\n", buffer);

    printf("[TEST] strcat validation completed.\n\n");
    return 0;
}
