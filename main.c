#include "systemcall.h"

int main(){
    
    char cmd[1024];

    do{
        write(STDOUT_FILENO,"% ",1);
        read(STDIN_FILENO,cmd,1024);
        //printf("%s\n",cmd);
    } while(cmd!=NULL);

    return 0;
}