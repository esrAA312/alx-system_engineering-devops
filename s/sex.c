#include "main.h"

void handle_exit(char *args[], int *exit_status)
{
	if (arg_count == 2)
		*exit_status = atoi(args[1]);
	exit(*exit_status);
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
