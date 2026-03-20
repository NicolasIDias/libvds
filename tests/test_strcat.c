#include <stdio.h>
#include <vds/string.h>

void validate(const char *test_name, const char *expected, const char *result) {
    if (vds_strcmp(expected, result) == 0) {
        printf("[OK] %s: '%s'\n", test_name, result);
    } else {
        printf("[FAIL] %s | Experado: '%s' | Obtido: '%s'\n", test_name, expected, result);
    }
}

int main() {
    printf("[SYSTEM CHECK] Iniciando validacao de concatenacao (strcat)...\n");

    char buffer[20] = "Hello"; 

    vds_strcat(buffer, " World", 20);
    validate("Concatenacao Simples", "Hello World", buffer);

    vds_strcat(buffer, " extra", 15); 
    validate("Seguranca contra Overflow", "Hello World ex", buffer);
    char cheio[5] = "Full";
    vds_strcat(cheio, "More", 5);
    validate("Buffer ja cheio", "Full", cheio);

    printf("[SYSTEM CHECK] Validacao de strcat concluida.\n\n");
    return 0;
}