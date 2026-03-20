#include <stdio.h>
#include <vds/string.h>

void validate(const char *test_name, const char *txt, size_t expected_size)
{
    size_t resultado = vds_strlen(txt);

    if (resultado == expected_size)
    {
        printf("[OK] %s: Tamanho %zu verificado.\n", test_name, resultado);
    }
    else
    {
        printf("[FAIL] %s: Esperava %zu, mas obteve %zu.\n", test_name, expected_size, resultado);
    }
}

int main()
{
    printf("[SYSTEM CHECK] Iniciando validacao do modulo de Strings...\n");
    validate("Palavra simples", "teste", 5);

    validate("Frase com espacos", "Teste numero dois", 17);

    validate("String vazia", "", 0);
    validate("Alfa-numerico", "teste numero 3", 14);

    printf("[SYSTEM CHECK] Modulo de strings validado com sucesso.\n\n");
    return 0;
}