#include "systemcall.h"
#include "_utilities.h"
#include "string.h"

#define NUM_CMDS 7

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

    for (i = 0; i < NUM_CMDS; i++)
    {
        if (strcmp(argv[1], commands[i].name) == 0)
        {
            commands[i].function(argv[2], argv[3]);
            return 1;
        }
    }
    commands[NUM_CMDS-1].function(argv[1]);
    return 1;
}