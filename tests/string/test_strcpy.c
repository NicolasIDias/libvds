#include <stdio.h>
#include <vds/vds_assert.h>
#include <vds/vds_string.h>

int main(void)
{
    printf("[TEST] Validating string copy (strcpy) function...\n");

    char buffer[100];

    buffer[0] = '\0';
    vds_strcpy(buffer, "Vanguard", 100);
    vds_assert(vds_strcmp(buffer, "Vanguard") == 0);
    printf("[PASS] Normal copy: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Vanguard", 4);
    vds_assert(vds_strcmp(buffer, "Van") == 0);
    printf("[PASS] Safe truncation: '%s'.\n", buffer);

    buffer[0] = 'X';
    vds_strcpy(buffer, "", 100);
    vds_assert(vds_strcmp(buffer, "") == 0);
    printf("[PASS] Empty string copy: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "ABC", 4);
    vds_assert(vds_strcmp(buffer, "ABC") == 0);
    printf("[PASS] Copy with exact size: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "X", 100);
    vds_assert(buffer[0] == 'X' && buffer[1] == '\0');
    printf("[PASS] Single character copy: '%s'.\n", buffer);

    buffer[0] = 'X';
    buffer[1] = 'Y';
    vds_strcpy(buffer, "TEST", 1);
    vds_assert(buffer[0] == '\0');
    printf("[PASS] Buffer too small: only null terminator.\n");

    buffer[0] = '\0';
    vds_strcpy(buffer, "Test@#$!", 100);
    vds_assert(vds_strcmp(buffer, "Test@#$!") == 0);
    printf("[PASS] Copy with special characters: '%s'.\n", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Lorem ipsum dolor sit amet", 100);
    vds_assert(vds_strcmp(buffer, "Lorem ipsum dolor sit amet") == 0);
    printf("[PASS] Long string copy: '%s'.\n", buffer);

    printf("[TEST] Copy validation completed.\n\n");
    return 0;
}
