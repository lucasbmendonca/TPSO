#include "systemcall.h"
#include "_utilities.h"
#include <string.h>
#include <stdlib.h>

#define NUM_CMDS 7
#define MAX_LENGHT 255

typedef struct cmd
{
    char *name;
    int (*function)();
} cmd;

cmd commands[NUM_CMDS] = {{"acrescenta", acrescenta},
                          {"apaga", apaga},
                          {"conta", conta},
                          {"informa", informa},
                          {"lista", lista},
                          {"mostra", mostra},
                          {"generico", executa_cmd_generico}};

int main(int argc, char *argv[])
{
    int i;
    char cmd_gen[MAX_LENGHT];
    cmd_gen[0] = '\0';

    //Para comandos criados
    for (i = 0; i < NUM_CMDS; i++)
    {
        if (strcmp(argv[0], commands[i].name) == 0)
        {
            commands[i].function(argv[1], argv[2]);
            return 1;
        }
    }
    //Para comandos genéricos
    for (i = 0; i < argc; i++)
    {       
        strcat(cmd_gen, argv[i]);
        strcat(cmd_gen, " ");
    }

    commands[NUM_CMDS-1].function(cmd_gen);
    return 1;
}