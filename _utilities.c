#include "_utilities.h"

char *converteItoa(int x)
{
    char resultado[30];
    char *final = NULL;
    int i = 0;
    int n;

    while (x != 0)
    {
        int rem = x % 10;
        resultado[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        i++;
        x = x / 10;
    }
    resultado[i] = '\0';

    final = malloc(i);
    int start = 0;
    int end = i - 1;
    while (end >= 0)
    {
        final[start] = resultado[end];
        start++;
        end--;
    }
    return final;
}

int qualTamanho(char *convertido)
{
    int i = 0;
    while (convertido[i] != '\0')
    {
        i++;
    }
    return i;
}

int tamanho(char *val, int opt)
{
    int x = 0;

    if (opt == 0)
    {
        while (val[x] != '\0')
        {
            x++;
        }

        return x;
    }
    else
    {
        while (val[x] != '\n')
        {
            x++;
        }

        return x;
    }
}

int comparar(char *valor, int opt)
{
    int tam = -1;
    if (opt == 0)
    {
        tam = tamanho(valor, 0);
    }
    else
    {
        tam = tamanho(valor, 1);
    }

    int conta = 0;

    char com1[] = "mostra";
    char com2[] = "conta";
    char com3[] = "apaga";
    char com4[] = "informa";
    char com5[] = "acrescenta";
    char com6[] = "lista";
    char com7[] = "generico";
    char com8[] = "termina";

    for (int i = 0; i < 8; i++)
    {
        conta = 0;

        switch (i)
        {
        case 0:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com1[x])
                    conta++;
            }
        }
        break;
        case 1:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com2[x])
                    conta++;
            }
        }
        break;
        case 2:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com3[x])
                    conta++;
            }
        }
        break;
        case 3:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com4[x])
                    conta++;
            }
        }
        break;
        case 4:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com5[x])
                    conta++;
            }
        }
        break;
        case 5:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com6[x])
                    conta++;
            }
        }
        break;
        case 6:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com7[x])
                    conta++;
            }
        }
        break;
        case 7:
        {
            for (int x = 0; x < tam; x++)
            {
                if (valor[x] == com8[x])
                    conta++;
            }
        }
        break;
        }

        if (conta == tam)
        {

            return i;
        }
    }
    return 6; //generico
}