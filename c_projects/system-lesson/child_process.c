/*
Child Process
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{

	pid_t pid;
	pid = fork();

	if (pid > 0)
	{
		printf("parent: %d , cid :  %d", getpid(), pid);
	}

	else if (pid == 0)
	{
		printf("child: %d , cid :  %d,  cid :  %d", getpid(), pid, getppid());
	}

	return 0;
}
