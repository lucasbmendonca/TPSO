#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    int n;
    char *conteudo = NULL;
    
    if(argv[1] != 2){
       perror( "Nome do ficheiro não encontrado" ); 
        exit(1);}

    struct stat filestat;
    if(stat(argv[1],&filestat)< 0){
        perror( "ficheiro nao existe" ); 
        exit(1);

    }
   
    int size = filestat.st_size;
    conteudo = (char*) calloc(n, size);
    fd = open(argv[1], O_RDONLY);
   
    read(fd, conteudo, size);
    write(1, conteudo, size);
    close(fd);
  
}

