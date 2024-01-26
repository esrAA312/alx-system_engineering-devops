#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - Creates an infinite loop.
 * Return: Always returns 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Entry point of the program
 * Return: Always returns 0.
 */
int main(void)
{
	pid_t chi;
	int x;

	for (x = 0; x < 5; x++)
	{
		chi = fork();

		if (chi == -1)
		{
			perror("Error creating child process");
			exit(EXIT_FAILURE);
		}

		if (chi == 0)
		{
			printf("Zombie process created, PID: %d\n", getpid());
			exit(0);
		}
	}

	infinite_while();

	return (0);
}

