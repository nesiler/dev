/*
 ============================================================================
 Name        : child.c
 Author      : Enes Diler
 Contact     : dilerenes@gmail.com
 Description : Creates new process with fork() and prints "a" and "B"
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	pid = fork();

	for (int i = 1; i < 5; i++)
	{

		sleep(1); // :)

		if (pid > 0) //parent process
		{
			printf("a\n");
		}

		else if (pid == 0) //child process
		{
			printf("B\n");
		}
	}

	return 0;
}
