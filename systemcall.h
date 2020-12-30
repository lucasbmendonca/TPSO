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
char *nomeUTL(char *idutl);
int informa(char *ficheiro);
int lista(char *ficheiro);
int mostra(char *ficheiro);