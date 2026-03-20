#include <vds/types.h>
#include <vds/string.h>

int strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    // Retorna a diferença aritmética dos caracteres onde eles divergiram
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}