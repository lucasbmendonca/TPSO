#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "_utilities.h"

#define termina "termina"

char **div_string(char *cmnd)
{
    int count = 1;

    for (int i = 0; cmnd[i] != '\0'; i++)
    {
        if (cmnd[i] == ' ')
            count++;
    }

    char *str = strdup(cmnd);

    char **result;
    int i = 0;
    char *token;

    result = (char **)calloc(count, sizeof(char *));

    token = strtok(str, " ");

    while (token != NULL && i < count)
    {
        result[i] = (char *)strdup(token);

        token = strtok(NULL, " ");
        i++;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int id, z;
    char comando[255];

    while (1)
    {
        write(1, "\n%", 2);
        int tam = read(0, comando, 255);
        comando[tam - 1] = '\0';

        if (comando == (char *)NULL || strcmp(comando, termina) == 0)
            exit(0);

        char **args = div_string(comando);

        id = fork();

        if (id == 0)
        {
            execvp("./process", args);
            write(1,"Não foi possível iniciar um novo processo para o comando\n",70);
            exit(1);
        }

        else if (id > 0)
        {
            wait((int *)0);
        }
        else if (id == -1)
        {
            write(1, "Erro.\n", 6);
        }
    }
}
