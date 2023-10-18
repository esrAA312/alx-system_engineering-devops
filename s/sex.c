#include "main.h"

void handle_exit(char *args[], int co)
{
	int exit_status = 0;

	if (co == 2)
		exit_status = atoi(args[1]);
	exit(exit_status);
}

void handle_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
