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
    int estado = 1, ponteiro = 0;
    const int tam = strlen(cadeia);

    while (1)
    {
        if (ponteiro > tam)
        {
            printf("Cadeia não reconhecida\n");
            return 1;
        }

        const char caracter = cadeia[ponteiro];

        switch (estado)
        {
            case 1:
                if (caracter == 'i')
                {
                    estado = 2;
                    break;
                }
                if (caracter == 'w')
                {
                    estado = 32;
                    break;
                }
                estado = 0;
                break;
            case 2:
                if (caracter == '(')
                {
                    estado = 3;
                    break;
                }
                estado = 0;
                break;
            case 3:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 4;
                    break;
                }
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 9;
                    break;
                }
                estado = 0;
                break;
            case 4:
                if (caracter == '+' || caracter == '-')
                {
                    estado = 5;
                    break;
                }
                estado = 0;
                break;
            case 5:
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 6;
                    break;
                }
                estado = 0;
                break;
            case 6:
                if (caracter == '>')
                {
                    estado = 7;
                    break;
                }
                estado = 0;
                break;
            case 7:
                if (caracter == '1')
                {
                    estado = 8;
                    break;
                }
                estado = 0;
                break;
            case 8:
                if (caracter == ')')
                {
                    estado = 11;
                    break;
                }
                estado = 0;
                break;
            case 9:
                if (caracter == '-')
                {
                    estado = 10;
                    break;
                }
                estado = 0;
                break;
            case 10:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 6;
                    break;
                }
                estado = 0;
                break;
            case 11:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 12;
                    break;
                }
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 14;
                    break;
                }
                estado = 0;
                break;
            case 12:
                if (caracter == '+' || caracter == '-')
                {
                    estado = 13;
                    break;
                }
                estado = 0;
                break;
            case 13:
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 16;
                    break;
                }
                estado = 0;
                break;
            case 14:
                if (caracter == '-')
                {
                    estado = 15;
                    break;
                }
                estado = 0;
                break;
            case 15:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 16;
                    break;
                }
                estado = 0;
                break;
            case 16:
                if (caracter == 'e')
                {
                    estado = 17;
                    break;
                }
                estado = 0;
                break;
            case 17:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 18;
                    break;
                }
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 20;
                    break;
                }
                estado = 0;
                break;
            case 18:
                if (caracter == '+' || caracter == '-')
                {
                    estado = 19;
                    break;
                }
                estado = 0;
                break;
            case 19:
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 22;
                    break;
                }
                estado = 0;
                break;
            case 20:
                if (caracter == '-')
                {
                    estado = 21;
                    break;
                }
                estado = 0;
                break;
            case 21:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 22;
                    break;
                }
                estado = 0;
                break;
            case 22:
                printf("Cadeia reconhecida\n");
                return 0;
            case 32:
                if (caracter == '(')
                {
                    estado = 33;
                    break;
                }
                estado = 0;
                break;
            case 33:
                if (caracter == 'x')
                {
                    estado = 34;
                    break;
                }
                estado = 0;
                break;
            case 34:
                if (caracter == '=')
                {
                    estado = 35;
                    break;
                }
                estado = 0;
                break;
            case 35:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 36;
                    break;
                }
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 37;
                    break;
                }
                estado = 0;
                break;
            case 36:
                if (caracter == '>')
                {
                    estado = 38;
                    break;
                }
                estado = 0;
                break;
            case 37:
                if (caracter == '>')
                {
                    estado = 38;
                    break;
                }
                estado = 0;
                break;
            case 38:
                if (caracter == '3')
                {
                    estado = 39;
                    break;
                }
                estado = 0;
                break;
            case 39:
                if (caracter == ')')
                {
                    estado = 40;
                    break;
                }
                estado = 0;
                break;
            case 40:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 41;
                    break;
                }
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 42;
                    break;
                }
                estado = 0;
                break;
            case 41:
                if (caracter == '+' || caracter == '-')
                {
                    estado = 44;
                    break;
                }
                estado = 0;
                break;
            case 42:
                if (caracter == '-')
                {
                    estado = 43;
                    break;
                }
                estado = 0;
                break;
            case 43:
                if (caracter == '3' || caracter == '4' || caracter == '5')
                {
                    estado = 45;
                    break;
                }
                estado = 0;
                break;
            case 44:
                if (caracter == '6' || caracter == '7' || caracter == '8')
                {
                    estado = 45;
                    break;
                }
                estado = 0;
                break;
            case 45:
                if (caracter == 'x')
                {
                    estado = 46;
                    break;
                }
                estado = 0;
                break;
            case 46:
                if (caracter == '=')
                {
                    estado = 47;
                    break;
                }
                estado = 0;
                break;
            case 47:
                if (caracter == 'x')
                {
                    estado = 48;
                    break;
                }
                estado = 0;
                break;
            case 48:
                if (caracter == '-')
                {
                    estado = 49;
                    break;
                }
                estado = 0;
                break;
            case 49:
                if(caracter == '3')
                {
                    estado = 50;
                    break;
                }
                estado = 0;
                break;
            case 50:
                printf("Cadeia reconhecida\n");
                return 0;
            default:
                printf("Cadeia não reconhecida\n");
                return 1;
        }

        ponteiro++;
    }
}