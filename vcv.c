#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checaVogal(char letra)
{
    const char vogais[] = "aeiouAEIOU";

    for (int i = 0; i < strlen(vogais); i++)
    {
        if (letra == vogais[i])
        {
            return 1;
        }
    }

    return 0;
}

int checaConsoante(char letra)
{
    if (isalpha(letra) && !checaVogal(letra))
    {
        return 1;
    }

    return 0;
}

int main(const int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Uso: ./vcv [input_file]\n");
        return 1;
    }

    const char *cadeia = argv[1];
    int estado = 1;
    const int tam = strlen(cadeia);

    for (int i = 0; i <= 3; i++)
    {
        const char caracter = cadeia[i];

        switch (estado)
        {
            case 1:
                if (checaVogal(caracter))
                {
                    estado = 2;
                    break;
                }
                estado = -1;
                break;
            case 2:
                if (checaConsoante(caracter))
                {
                    estado = 3;
                    break;
                }
                estado = -1;
                break;
            case 3:
                if (checaVogal(caracter))
                {
                    estado = 4;
                    break;
                }
                estado = -1;
                break;
            case 4:
                if (i != tam)
                {
                    printf("Cadeia não reconhecida");
                    return 1;
                }
                printf("Cadeia reconhecida");
                return 0;
            default:
                printf("Cadeia não reconhecida");
                return 1;
        }
    }

    printf("Cadeia não reconhecida");
    return 1;
}