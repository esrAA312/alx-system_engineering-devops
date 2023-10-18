#include "main.h"

void execute_external_command(char *args[], int *exit_status)
{
pid_t child_pid = fork();

if (child_pid < 0)

	perror("fork");
	exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
	char *envp[] = { NULL };

	execve(args[0], args, envp);
	perror("execve");
	_exit(EXIT_FAILURE);
}
else
{
	int status;

	waitpid(child_pid, &status, 0);
	*exit_status = WEXITSTATUS(status);
}
}
