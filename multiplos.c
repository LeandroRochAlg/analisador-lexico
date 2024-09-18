#include <stdio.h>
#include <string.h>

int main(const int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Uso: ./gramatica [input_file]\n");
        return 1;
    }

    const char *cadeia = argv[1];
    int estado = 0, ponteiro = 0;
    const int tam = strlen(cadeia);

    while (1)
    {
        const char caracter = cadeia[ponteiro];

        switch (estado)
        {
            case 0:
                if (ponteiro == tam)
                {
                    printf("Cadeia reconhecida");
                    return 0;
                }
                if (caracter == '0')
                {
                    estado = 0;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 1;
                    break;
                }
                estado = -1;
                break;
            case 1:
                if (caracter == '0')
                {
                    estado = 2;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 3;
                    break;
                }
                estado = -1;
                break;
            case 2:
                if (caracter == '0')
                {
                    estado = 4;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 5;
                    break;
                }
                estado = -1;
                break;
            case 3:
                if (caracter == '0')
                {
                    estado = 0;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 1;
                    break;
                }
                estado = -1;
                break;
            case 4:
                if (caracter == '0')
                {
                    estado = 2;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 3;
                    break;
                }
                estado = -1;
                break;
            case 5:
                if (caracter == '0')
                {
                    estado = 4;
                    break;
                }
                if (caracter == '1')
                {
                    estado = 5;
                    break;
                }
                estado = -1;
                break;
            default:
                printf("Cadeia não reconhecida");
                return 1;
        }

        ponteiro++;
    }
}