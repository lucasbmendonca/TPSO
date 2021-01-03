#include "systemcall.h"
#include "_utilities.h"
#include "string.h"

#define NUM_CMDS 7

//function type

typedef struct cmd
{
    int idx;
    char *name;
    int (*function)();
} cmd;

cmd commands[NUM_CMDS] = {{0, "acrescenta", acrescenta},
                          {1, "apaga", apaga},
                          {2, "conta", conta},
                          {3, "informa", informa},
                          {4, "lista", lista},
                          {5, "mostra", mostra},
                          {6, "generico", executa_cmd_generico}};

char **split_str(char *cmnd)
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

    result = (char **)calloc(count, sizeof(char *)); // cria arrays de apontadores para strings

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
    for (int i = 0; i < NUM_CMDS; i++)
    {
        printf("%s\n", argv[1]);
        if (strcmp(argv[1], commands[i].name) == 0)
        {
            printf("%s\n", commands[i].name);
            commands[i].function(split_str(*(argv)));
        }
    }
}