#include <stdio.h>
#include <vds/types.h>

int main()
{
    printf("[SYSTEM CHECK] Iniciando validacao dos tipos core...\n");

    size_t ptr_size = sizeof(void *);
    size_t size_size_t = sizeof(size_t);

    if (ptr_size == size_size_t)
    {
        printf("[OK] size_t configurado corretamente (%zu bytes).\n", size_size_t);
    }
    else
    {
        printf("[FAIL] Inconsistencia no size_t!\n");
    }

    // void *null_ptr = NULL;
    // if (null_ptr == (void*)0) {
    //     printf("[OK] Macro NULL operando corretamente.\n");
    // }

    bool active = true;
    if (active == true && false == 0)
    {
        printf("[OK] Logica booleana base operacional.\n");
    }

    printf("[SYSTEM CHECK] Validacao de tipos concluida.\n\n");
    return 0;
}