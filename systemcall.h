#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>

int acrescenta(char *ficheiro_o, char *ficheiro_d);
int apaga(char *ficheiro);
int conta(char *argumento);
void nomeUTL(char *idutl, char *resultado);
int informa(char *ficheiro);
int lista(char *ficheiro);
int mostra(char *ficheiro);
int executa_cmd_generico(char *str);