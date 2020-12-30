#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>

char * converteItoa(int x);
int qualTamanho(char *convertido);
int tamanho(char *val, int opt);
int comparar(char *valor, int opt);