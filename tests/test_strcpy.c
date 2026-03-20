#include <stdio.h>
#include <vds/string.h>

void validate_copy(const char *test_name, const char *expected, const char *result) {
    if (vds_strcmp(expected, result) == 0) {
        printf("[OK] %s: '%s'\n", test_name, result);
    } else {
        printf("[FAIL] %s\n", test_name);
        printf("       -> Experado: '%s'\n", expected);
        printf("       -> Obtido:   '%s'\n", result);
    }
}

int main() {
    printf("[SYSTEM CHECK] Iniciando validacao de copia de memoria (strcpy)...\n");

    char buffer[100];

    buffer[0] = '\0'; 
    vds_strcpy(buffer, "Vanguard", 100);
    validate_copy("Copia Normal", "Vanguard", buffer);

    buffer[0] = '\0';
    vds_strcpy(buffer, "Vanguard", 4);
    validate_copy("Truncamento Seguro", "Van", buffer);

    buffer[0] = 'X'; 
    vds_strcpy(buffer, "", 100);
    validate_copy("Copia String Vazia", "", buffer);


    printf("[SYSTEM CHECK] Validacao de copia concluida.\n\n");
    return 0;
}