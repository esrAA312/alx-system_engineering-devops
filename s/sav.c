#include "main.h"

void handle_ls(char *args)
{
	if (arg_count == 1 || (arg_count == 2 && strcmp(args[1], "-l") == 0))
{
		char *ls_args[4] = { "ls", "-l", NULL };
		pid_t ls_pid = fork();

		if (ls_pid == 0)
		{
			char *envp[] = { NULL };

			execve("/bin/ls", ls_args, envp);
			perror("execve");
			_exit(EXIT_FAILURE); }
		else
		{
			int ls_status;

			waitpid(ls_pid, &ls_status, 0); }}
		else if (arg_count == 2 && strcmp(args[1], "/tmp") == 0)
{
		char *ls_args[4] = { "ls", "/tmp", NULL };

		pid_t ls_pid = fork();

		if (ls_pid == 0)
		{
			char *envp[] = { NULL };

			execve("/bin/ls", ls_args, envp);
			perror("execve");
			_exit(EXIT_FAILURE); }
		else
		{
			int ls_status;

			waitpid(ls_pid, &ls_status, 0); }
		else
		write(STDOUT_FILENO, "Usage: ls or ls -l or ls /tmp\n", 31)
}
