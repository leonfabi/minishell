#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int	id = fork();
	int	n;
	int	i;
	if (id == 0)
		n = 1;
	else
		n = 6;
	printf("Current id: %d, parent id: %d\n", getpid(), getppid());
	if (id != 0)
		wait(NULL);
	for (i = n; i < n + 5; i++)
	{
		printf("%d", i);
		fflush(stdout);
	}
	// if (id == 0)
	// 	printf("Hello from child process\n");
	// else
	// 	printf("Hello from the main process\n");
	return 0;
}