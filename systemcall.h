#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <error.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* Definir o nome tamanho_max como 1024 quer dizer que usando este nome na declaração
*  de um array de caracteres esse array vai ter um comprimento de 1024 caracteres     
*/
#define tamanho_max 1024

//Enumerar as paravras... GENERICO = 0, VAIPARA = 1, ...., NUM_COMANDOS = ao numero de comandos disponivel
typedef enum {
	GENERICO,
	MOSTRA,
	LISTA,
    INFORMA,
	APAGA,
	ACRESCENTA,
	CONTA,
	NUM_COMANDOS
} tipocomando;
						  
//Declaração das variavéis globais
char *diretorio_atual = NULL;
char *sem_enter = NULL;
int soc, n_soc;
struct sockaddr_in soc_addr;
struct hostent *he;
char *caminho;
char *cwd_name = NULL;

//Construção de um array multidimensional que armazena o nome de cada comando linha a linha 
//char nome_cmd [NUM_COMANDOS][6] = { {"mostra"}, {"conta"}, {"apaga"}, {"informa"}, {"acrescenta"}, {"lista"} };

char *mostra(FILE *arq);
char *conta(FILE *arq);
char *apaga(FILE *arq);

/*char *get_cmd(char *nome_comando);
int cmd_generico(char *str);
tipocomando procura_n_comando(char *nome_comando);
int lista(char *nome_comando, int x);
int informa(char *nome_comando);
int acrescenta(char *nome_comando, int opcao);
void server_handle_client(int n_soc);*/