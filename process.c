#include "systemcall.h"
#include "_utilities.h"
#include <string.h>
#include <stdlib.h>

#define NUM_CMDS 7
#define MAX_LENGHT 255
#define OK '1'
#define NOT_OK '0'

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

void display_msg_for_cmd(int type, char *cmd);

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
            display_msg_for_cmd(commands[i].function(argv[1], argv[2]),argv[0]);
            return 1;
        }
    }
    //Para comandos genéricos
    for (i = 0; i < argc; i++)
    {       
        strcat(cmd_gen, argv[i]);
        strcat(cmd_gen, " ");
    }

    display_msg_for_cmd(commands[NUM_CMDS-1].function(cmd_gen),argv[0]);
    return 1;
}

void display_msg_for_cmd(int type, char *cmd)
{  
    char str[1];
    if (type == 0)
        str[0] = NOT_OK;
    else
        str[0] = OK;
    
    write(1, "\nTerminou comando ", 20);
    write(1, cmd, qualTamanho(cmd));
    write(1, " com codigo ", 12);
    write(1, str, 1);
    write(1, "\n", 2);
}