/*
 
 */

/*#include <stdio.h>
#include <stdlib.h>

int a;
int b = 10;

int main(void)
{
    char str1[] = "merhaba";
    char *str2 = "merhaba";
    printf("%ld ",sizeof(str1));
    printf("%ld",sizeof(str2));

    static int c = 100;
    static int d;
    int e = 5;
    int *f = malloc(sizeof(int));
    *f = 5;
    return 0;
}*/

/*#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    printf("parent process id: %d\n", pid);
    fork(); //1
    fork(); //2
    fork(); //3
    pid = getpid();
    printf("hello from pid %d\n", pid);
    return 0;
}*/

#include <stdio.h>

#include <sys/types.h>

#include <unistd.h>

int main2()
{
    pid_t pid = getpid();
    printf("parent process id: %d\n", pid);
    for (int i = 0; i < 3; i++)
    {
        pid_t cpid = fork(); //1
        if (cpid == 0)
        { //BU KISIM KAC PROCCESS TARAFINDAN CALISTIRILIR
            pid = getpid();
            printf("hello from child process:  %d\n", pid);
        }
    }
    return 0;
}
