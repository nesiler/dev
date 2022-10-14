/*
 ============================================================================
 Name        : programs.c
 Author      : Enes Diler
 Contact     : dilerenes@gmail.com
 Description : reads file and gets program name and arguments for launch
  ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define atoa(x) #x

int nwords(char *str) //counts words from file
{

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            count++;
    }

    return count + 1;
}

void sargs(char **args, char *buf) //separate all words from file to another array
{
    char tbuf[BUFSIZ]; //temporary char pointer
    strcpy(tbuf, buf);

    char *word;
    word = strtok(tbuf, " ");
    int i = 0;

    while (word != NULL)
    {
        int len = strlen(word);

        args[i] = malloc((len + 1) * sizeof(char)); //len kelime uzunluğu
        strncpy(args[i], word, len);

        word = strtok(NULL, " ");
        i++;
    }
}

void cprocess(char *buf)
{

    char **args = malloc(nwords(buf) * sizeof(char *));
    sargs(args, buf);

    char prog[50] = "/usr/bin/";
    strcat(prog, args[0]);

    pid_t pid;
    pid = fork();

    if (pid == 0) //child process
    {
        printf("Child Process ID: %d , Parent Process ID:  %d\n", getpid(), getppid());
        execv(prog, args);
    }
}

void cprocess1(char *buf)
{
    pid_t pid;
    pid = fork();

    if (pid == 0) //child process
    {
        printf("Child Process ID: %d , Parent Process ID:  %d\n", getpid(), getppid());
        execl("/bin/sh", "sh", "-c", buf, (char *)NULL);
    }
}

int main(int argc, char **argv)
{
    int fd = open("programs.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("cannot open file: ");
        return -1;
    }

    ssize_t ret;
    char buf[BUFSIZ];
    ret = read(fd, buf, BUFSIZ);

    if (ret == -1)
    {
        perror("cannot read");
        close(fd);
        return -1;
    }

    buf[ret] = '\0';

    cprocess(buf);
    cprocess1(buf);

    close(fd);

    return 0;
}