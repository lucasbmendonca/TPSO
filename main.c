#include "_utilities.h"
#include "systemcall.h"

int main(int argc, char *argv[])
{
    /*if (argc != 1)
    {
        write(1, "Para iniciar execute ./main sem argumentos", 43);
        write(1, "\n", 1);
        return 1;
    }*/

    char comando[255];
    char cmd[255];
    char arg1[255];
    char arg2[255];
    int conta_args = 0;
    int res = 0;

    int x = 0;
    while (x != 7)
    {
        for (int d = 0; d < 255; d++) //reset
        {
            comando[d] = '\0';
            cmd[d] = '\0';
            arg1[d] = '\0';
            arg2[d] = '\0';
        }

        write(1, "%", 1);
        read(0, comando, 255);
        int y = 0;
        conta_args = 0;

        if (comando[0] != '\n')
        {
            // quantos argumentos??
            while (comando[y] != '\n')
            {
                if (comando[0] == ' ')
                {
                    while (comando[y] == ' ')
                    {
                        y++;
                    }
                }
                else
                {
                    int j = 0;
                    int seg = 0;
                    int ter = 0;
                    while (comando[y] != '\n')
                    {
                        if (conta_args == 0 && comando[y] != ' ')
                        {
                            cmd[j] = comando[y];

                            y++;
                            j++;
                        }
                        else
                        {

                            if (comando[y] == ' ')
                            {
                                conta_args++;
                                while (comando[y] == ' ')
                                {
                                    y++;
                                }
                            }
                            if (conta_args == 1 && comando[y] != ' ')
                            {
                                cmd[j] = '\0';
                                arg1[seg] = comando[y];
                                y++;
                                seg++;
                            }
                            if (conta_args == 2 && comando[y] != ' ')
                            {
                                arg1[seg] = '\0';
                                arg2[ter] = comando[y];
                                y++;
                                ter++;
                            }
                            if (conta_args > 2)
                            {
                                arg1[seg] = '\0';
                                arg2[ter] = '\0';
                                y++;
                            }
                        }
                        arg1[seg] = '\0';
                        arg2[ter] = '\0';
                    }
                }
            }

            int m = comparar(cmd, 0);
            x = m;

            switch (m)
            {
            case 0:
            {
                res = mostra(arg1);
            }
            break;
            case 1:
            {
                res = conta(arg1);
                write(1, "\n", 1);
            }
            break;
            case 2:
            {
                res = apaga(arg1);
            }
            break;
            case 3:
            {
                res = informa(arg1);
            }
            break;
            case 4:
            {
                res = acrescenta(arg1, arg2);
            }
            break;
            case 5:
            {
                res = lista(arg1);
            }
            break;
            default:
                system(comando);
                break;
            }
        }
    }
    return 0;
}