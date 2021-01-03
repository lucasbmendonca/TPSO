#include "systemcall.h"
#include "_utilities.h"

int acrescenta(char *ficheiro_o, char *ficheiro_d)
{
    int fd, fd1;
    int n, ret;
    char *conteudo = NULL;
    char ch;
    int count = 0;

    struct stat filestat1;
    struct stat filestat2;

    printf("%s%s\n",ficheiro_o,ficheiro_d);
    if (stat(ficheiro_o, &filestat1) < 0)
    {
        perror("ficheiro de origem nao existe");
        return 0;
    }
    if (stat(ficheiro_d, &filestat2) < 0)
    {
        perror("ficheiro de Destino nao existe");
        return 0;
    }

    int size = filestat1.st_size;

    if ((fd = open(ficheiro_o, O_RDONLY)) == -1)
    {
        perror("open");
        return 0;
    }

    conteudo = (char *)calloc(n, size);
    int tamanho = read(fd, conteudo, size);
    close(fd);

    fd = open(ficheiro_d, O_RDWR | O_APPEND);

    if (fd == -1)
        return 0;
    
    tamanho = write(fd, conteudo, size);
    close(fd);

    return 1;
}

int apaga(char *ficheiro)
{
    int fd, n;
    int count = 1;
    char *conteudo = NULL;
    char *final = NULL;
    char *num = NULL;
    int i = 0;

    struct stat filestat;
    if (stat(ficheiro, &filestat) < 0)
    {
        perror("ficheiro nao existe");
        return 1;
    }

    fd = open(ficheiro, O_RDONLY);
    if (fd == -1)
    {
        close(fd);
        return 1;
    }
    else
    {
        unlink(ficheiro);
    }

    return 1;
}

int conta(char *argumento)
{
    int fd;
    int count = 0;
    int i = 0;
    char ch;
    int ret;

    struct stat filestat;
    if (stat(argumento, &filestat) < 0)
    {
        perror("ficheiro nao existe");
        return 2;
    }

    if ((fd = open(argumento, O_RDONLY)) == -1)
    {
        perror("open");
    }

    while ((ret = read(fd, &ch, 1) != 0))
    {
        count++;
    }

    char *convertido = converteItoa(count);
    int tamanho = qualTamanho(convertido);

    write(1, convertido, tamanho);
    free(convertido);
    return 1;
}

void nomeUTL(char *idutl, char *resultado)
{
    char id[4] = "1000";
    int fd;
    int conta_linhas = 0;
    int conta_2pontos = 0;
    int conta_iguais = 0;
    int conta_nome = 0;
    int conta_id = 0;
    int i = 0;
    int j = 0;
    //char *resultado = NULL;
    char nome[20];
    char uid[20];
    char ch;
    int ret;
    if ((fd = open("/etc/passwd", O_RDONLY)) == -1)
        perror("open");
    while ((ret = read(fd, &ch, 1) != 0))
    {
        //enquanto não for igual a : nem a enter
        if (ch != ':' && ch != '\n')
        {
            //verificar em que parte da string estou
            if (conta_2pontos == 0) //parte do nome
            {
                nome[i] = ch;
                i++;
                conta_nome++; //saber o tamanho do array nome
            }
            else if (conta_2pontos == 2) //começa a comparar id
            {
                i = 0;
                if (ch == id[j])
                {
                    j++;
                    conta_id++;
                }
                else
                {
                    conta_id++;
                }
            }
            else if (conta_2pontos == 3) //já temos o nome e o id
            {
                if (j == conta_id && j == 4) //são iguais
                {
                    int x = 0;
                    for (x = 0; x < conta_nome; x++)
                    {
                        resultado[x] = nome[x];
                    }
                }
                else
                {
                    int x = 0;
                    for (x = 0; x < conta_nome; x++)
                    {
                        nome[x] = '\0';
                    }
                }
            }
        }

        if (ch == ':')
        {
            conta_2pontos++;
        }

        if (ch == '\n')
        {
            conta_2pontos = 0;
            conta_iguais = 0;
            conta_linhas++;
            conta_id = 0;
            conta_nome = 0;
            j = 0;
            i = 0;
        }
    }
}

int informa(char *ficheiro)
{
    int num = 0;
    char conteudo[10];
    char *final = NULL;
    int i = 0;
    int n = 0;
    DIR *dp;
    struct dirent *dirp;

    struct stat fileStat;

    stat(ficheiro, &fileStat);

    if ((fileStat.st_mode & S_IFMT) == S_IFREG) /* É ficheiro */
    {
        write(1, (S_ISDIR(fileStat.st_mode)) ? "d" : "-", 1);
        write(1, (fileStat.st_mode & S_IRUSR) ? "r" : "-", 1);
        write(1, (fileStat.st_mode & S_IWUSR) ? "w" : "-", 1);
        write(1, (fileStat.st_mode & S_IXUSR) ? "x" : "-", 1);
        write(1, (fileStat.st_mode & S_IRGRP) ? "r" : "-", 1);
        write(1, (fileStat.st_mode & S_IWGRP) ? "w" : "-", 1);
        write(1, (fileStat.st_mode & S_IXGRP) ? "x" : "-", 1);
        write(1, (fileStat.st_mode & S_IROTH) ? "r" : "-", 1);
        write(1, (fileStat.st_mode & S_IWOTH) ? "w" : "-", 1);
        write(1, (fileStat.st_mode & S_IXOTH) ? "x" : "-", 1);

        char *convertido = converteItoa(fileStat.st_nlink); //conver o userid

        int tamanho = qualTamanho(convertido);
        write(1, " ", 1);
        write(1, convertido, tamanho);
        free(convertido);
        write(1, " ", 1);
        char nome[255];

        nomeUTL(converteItoa(fileStat.st_uid), nome);
        int s = qualTamanho(nome);
        write(1, nome, s);
        //free(nome);
        write(1, " ", 1);

        convertido = converteItoa(fileStat.st_size);
        tamanho = qualTamanho(convertido);

        write(1, " ", 1);
        write(1, convertido, tamanho);
        free(convertido);
        write(1, " ", 1);
        //s = qualTamanho(dirp->d_name);
        //write(1,dirp->d_name,s);

        s = qualTamanho(ficheiro);
        write(1, ficheiro, s);

        write(1, " File inode: ", 13);
        convertido = converteItoa(fileStat.st_ino);
        tamanho = qualTamanho(convertido);
        write(1, convertido, tamanho);
        free(convertido);

        write(1, "\n\n", 1);
    }
    else
    {
        if ((dp = opendir(ficheiro)) == NULL)
        {
            perror("can’t open");
            return 0;
        }
        while ((dirp = readdir(dp)) != NULL)
        {
            stat(dirp->d_name, &fileStat);
            write(1, (S_ISDIR(fileStat.st_mode)) ? "d" : "-", 1);
            write(1, (fileStat.st_mode & S_IRUSR) ? "r" : "-", 1);
            write(1, (fileStat.st_mode & S_IWUSR) ? "w" : "-", 1);
            write(1, (fileStat.st_mode & S_IXUSR) ? "x" : "-", 1);
            write(1, (fileStat.st_mode & S_IRGRP) ? "r" : "-", 1);
            write(1, (fileStat.st_mode & S_IWGRP) ? "w" : "-", 1);
            write(1, (fileStat.st_mode & S_IXGRP) ? "x" : "-", 1);
            write(1, (fileStat.st_mode & S_IROTH) ? "r" : "-", 1);
            write(1, (fileStat.st_mode & S_IWOTH) ? "w" : "-", 1);
            write(1, (fileStat.st_mode & S_IXOTH) ? "x" : "-", 1);

            char *convertido = converteItoa(fileStat.st_nlink); //conver o userid

            int tamanho = qualTamanho(convertido);
            write(1, " ", 1);
            write(1, convertido, tamanho);
            free(convertido);
            write(1, " ", 1);

            char nome[400];

            nomeUTL(converteItoa(fileStat.st_uid), nome);
            int s = qualTamanho(nome);
            write(1, nome, s);
            //free(nome);
            write(1, " ", 1);

            convertido = converteItoa(fileStat.st_size);
            tamanho = qualTamanho(convertido);

            write(1, " ", 1);
            write(1, convertido, tamanho);
            free(convertido);
            write(1, " ", 1);
            s = qualTamanho(dirp->d_name);
            write(1, dirp->d_name, s);

            write(1, " File inode: ", 13);
            convertido = converteItoa(fileStat.st_ino);
            tamanho = qualTamanho(convertido);
            write(1, convertido, tamanho);
            free(convertido);

            write(1, "\n\n", 1);
        }
    }
    return 1;
}

int lista(char *ficheiro)
{
    char *caminho;
    DIR *dp;
    struct dirent *dirp;
    struct stat sb;
    struct stat tam;
    int i = 0;
    caminho = getcwd(NULL, 0);

    if (ficheiro == NULL)
    {
        dp = opendir("./");
    }
    else if(ficheiro[0] == '\0')
    {
        dp = opendir("./");
    }
    else
    {

        if (chdir(ficheiro) != 0)
        {
            perror("O caminho não existe");
            return 1;
        }
        dp = opendir(".");
        if (dp == NULL)
            perror("Não foi possivél obter dados!!!");
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        if (stat(dirp->d_name, &sb) == 0)
        {
            if ((sb.st_mode & S_IFMT) == S_IFREG) /* É ficheiro */
            {
                write(1, "[F] ", 4);
            }
            else
            {
                write(1, "[*D] ", 5);
            }

            char *nome = NULL;

            i = 0;

            nome = dirp->d_name;

            while (nome[i] != '\0')
            {
                //printf("%d - %c",i, nome[i]);
                i++;
            }

            write(1, nome, i);
            write(1, "\n", 1);
        }
    }
    closedir(dp);
    chdir(caminho);
    return 1;
}

int mostra(char *ficheiro)
{
    int fd, ret;
    int n, count = 0;
    char *conteudo = NULL;
    char ch;

    struct stat filestat;
    if (stat(ficheiro, &filestat) < 0)
    {
        perror("ficheiro nao existe");
        return 1;
    }

    if ((fd = open(ficheiro, O_RDONLY)) == -1)
    {
        perror("open");
    }

    conteudo = (char *)malloc(count);
    while ((ret = read(fd, &ch, 1) != 0))
    {
        conteudo[count] = ch;
        count++;
    }

    write(1, conteudo, count);
    free(conteudo);
    close(fd);
    return 1;
}

int executa_cmd_generico(char *str)
{
    system(str);
    return 1;
}