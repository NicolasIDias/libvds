#include <stdio.h>
#include <vds/string.h>

/* 0 se forem iguais.
 * <0 se s1 for menor que s2.
 * >0 se s1 for maior que s2.
 */
void validate_strcmp(const char *test_name, const char *s1, const char *s2, int expected_result)
{
    int resultado = vds_strcmp(s1, s2);

    int status_ok = 0;
    if (expected_result == 0 && resultado == 0)
        status_ok = 1;
    else if (expected_result < 0 && resultado < 0)
        status_ok = 1;
    else if (expected_result > 0 && resultado > 0)
        status_ok = 1;

    if (status_ok)
    {
        printf("[OK] %s: '%s' vs '%s' (Retornou: %d)\n", test_name, s1, s2, resultado);
    }
    else
    {
        printf("[FAIL] %s: '%s' vs '%s'\n", test_name, s1, s2);
        printf("       -> Retornou %d (Incorreto para este cenario)\n", resultado);
    }
}

int main()
{
    printf("[SYSTEM CHECK] Iniciando validacao do strcmp...\n");

    validate_strcmp("Strings Iguais", "Teste1", "Teste1", 0);

    validate_strcmp("S1 Menor que S2", "Apple", "Banana", -1);
    validate_strcmp("S1 Maior que S2", "Banana", "Apple", 1);

    validate_strcmp("Case Sensitive", "estados unidos", "Estados Unidos", 1);

    validate_strcmp("S1 mais curta", "Tes", "Teste", -1);
    validate_strcmp("S1 mais longa", "Teste", "Tes", 1);

    validate_strcmp("Ambas Vazias", "", "", 0);
    validate_strcmp("S1 Vazia", "", "A", -1);
    validate_strcmp("S2 Vazia", "A", "", 1);

    printf("[SYSTEM CHECK] Validacao do strcmp concluida.\n\n");
    return 0;
}